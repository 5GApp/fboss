#pragma once

#include <vector>

#include "fboss/agent/types.h"
#include "fboss/qsfp_service/module/Transceiver.h"
#include "fboss/agent/gen-cpp2/switch_config_types.h"
#include "fboss/lib/i2c/gen-cpp2/i2c_controller_stats_types.h"

namespace facebook { namespace fboss {
class TransceiverManager {
 public:
  TransceiverManager() {};
  virtual ~TransceiverManager() {};
  virtual void loadConfig() = 0;
  virtual void initTransceiverMap() = 0;
  virtual void getTransceiversInfo(std::map<int32_t, TransceiverInfo>& info,
    std::unique_ptr<std::vector<int32_t>> ids) = 0;
  virtual void getTransceiversRawDOMData(std::map<int32_t, RawDOMData>& info,
    std::unique_ptr<std::vector<int32_t>> ids) = 0;
  virtual void customizeTransceiver(int32_t idx, cfg::PortSpeed speed) = 0;
  virtual void syncPorts(
    std::map<int32_t, TransceiverInfo>& info,
    std::unique_ptr<std::map<int32_t, PortStatus>> ports) = 0;

  bool isValidTransceiver(int32_t id) {
    return id < transceivers_.size() && id >= 0;
  }
  virtual int getNumQsfpModules() = 0;
  virtual void refreshTransceivers() = 0;
  virtual int scanTransceiverPresence(
      std::unique_ptr<std::vector<int32_t>> ids) = 0;
  virtual int numPortsPerTransceiver() = 0;

  /* Virtual function to return the i2c transactions stats in a platform.
   * This will be overridden by derived classes which are platform specific
   * and has the platform specific implementation for this counter
   */
  virtual std::vector<std::reference_wrapper<const I2cControllerStats>>
    getI2cControllerStats() const = 0;

 private:
  // Forbidden copy constructor and assignment operator
  TransceiverManager(TransceiverManager const &) = delete;
  TransceiverManager& operator=(TransceiverManager const &) = delete;
 protected:
  std::vector<std::unique_ptr<Transceiver>> transceivers_;
};
}} // facebook::fboss
