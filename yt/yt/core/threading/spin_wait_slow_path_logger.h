#pragma once

#include <util/datetime/base.h>

namespace NYT::NThreading {

////////////////////////////////////////////////////////////////////////////////

void SetSpinWaitSlowPathLoggingThreshold(TDuration threshold);

////////////////////////////////////////////////////////////////////////////////

} // namespace NYT::NThreading
