// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/enterprise_util.h"

#include "base/win/win_util.h"
#include "base/win/windows_version.h"

namespace base {

bool IsManagedDevice() {
  // Legacy domain join does not actually guarantee that the device is managed,
  // however there is no API that can be used to determine if any group policies
  // are actually being applied. As such, for these devices we need to assume
  // they are managed.
  // IsDeviceRegisteredWithManagement() can be true for devices running the Home
  // sku, however the Home sku does not allow for management of the web browser.
  // As such, we only include devices running a non-Home sku.
  // In addition, simply being joined to AAD does not mean the device is being
  // managed by the AAD tenant, so checking for AAD join is not included here.
  return base::win::IsEnrolledToDomain() ||
         (base::win::IsDeviceRegisteredWithManagement() &&
          (base::win::OSInfo::GetInstance()->version_type() !=
           base::win::SUITE_HOME));
}

bool IsEnterpriseDevice() {
  // Both legacy domain join and AAD join represent machine-wide enterprise
  // join.
  return base::win::IsEnrolledToDomain() || base::win::IsJoinedToAzureAD();
}

}  // namespace base
