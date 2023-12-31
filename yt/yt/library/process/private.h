#pragma once

#include <yt/yt/core/logging/log.h>

namespace NYT::NPipes {

////////////////////////////////////////////////////////////////////////////////

inline const NLogging::TLogger PipesLogger("Pipes");
inline const NLogging::TLogger PtyLogger("Pty");

////////////////////////////////////////////////////////////////////////////////

} // namespace NYT::NPipes
