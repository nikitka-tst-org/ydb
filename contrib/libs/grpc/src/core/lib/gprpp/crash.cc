// Copyright 2022 gRPC authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <grpc/support/port_platform.h>

#include "src/core/lib/gprpp/crash.h"

#include <stdlib.h>

#include <util/generic/string.h>
#include <util/string/cast.h>

#include <grpc/support/log.h>

namespace {
    grpc_core::CustomCrashFunction custom_crash;
}

namespace grpc_core {

void SetCustomCrashFunction(CustomCrashFunction fn) {
    custom_crash = fn;
}

void Crash(y_absl::string_view message, SourceLocation location) {
  gpr_log(location.file(), location.line(), GPR_LOG_SEVERITY_ERROR, "%s",
          TString(message).c_str());
  if (custom_crash) {
      custom_crash(location.file(), location.line(), TString(message).c_str());
  } else {
      abort();
  }
}

}  // namespace grpc_core
