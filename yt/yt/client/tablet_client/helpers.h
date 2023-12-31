#pragma once

#include "public.h"

namespace NYT::NTabletClient {

////////////////////////////////////////////////////////////////////////////////

bool IsStableReplicaMode(ETableReplicaMode mode);
bool IsStableReplicaState(ETableReplicaState state);

////////////////////////////////////////////////////////////////////////////////

} // namespace NYT::NTabletClient
