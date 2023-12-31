#pragma once

#include <yt/yt/core/misc/public.h>

namespace NYT::NThreading {

////////////////////////////////////////////////////////////////////////////////

using TThreadId = size_t;
constexpr size_t InvalidThreadId = 0;

DEFINE_ENUM(EThreadPriority,
    (Normal)
    (RealTime)
);

////////////////////////////////////////////////////////////////////////////////

} // namespace NYT::NThreading
