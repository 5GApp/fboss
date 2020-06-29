/*
 *  Copyright (c) 2004-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#include "fboss/agent/hw/test/HwTestAclUtils.h"

#include "fboss/agent/FbossError.h"

namespace facebook::fboss::utility {
int getAclTableNumAclEntries(const HwSwitch* /*hwSwitch*/) {
  throw FbossError("Not implemented");
  return 0;
}

void checkSwHwAclMatch(
    const HwSwitch* /*hw*/,
    std::shared_ptr<SwitchState> /*state*/,
    const std::string& /*aclName*/) {
  throw FbossError("Not implemented");
}

bool isAclTableEnabled(const HwSwitch* /*hwSwitch*/) {
  throw FbossError("Not implemented");
  return false;
}

template bool isQualifierPresent<cfg::IpFragMatch>(
    const HwSwitch* hwSwitch,
    const std::shared_ptr<SwitchState>& state,
    const std::string& aclName);

template <typename T>
bool isQualifierPresent(
    const HwSwitch* /*hwSwitch*/,
    const std::shared_ptr<SwitchState>& /*state*/,
    const std::string& /*aclName*/) {
  throw FbossError("Not implemented");
  return false;
}

} // namespace facebook::fboss::utility
