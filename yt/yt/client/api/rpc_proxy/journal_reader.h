#pragma once

#include "api_service_proxy.h"

namespace NYT::NApi::NRpcProxy {

////////////////////////////////////////////////////////////////////////////////

IJournalReaderPtr CreateJournalReader(
    TApiServiceProxy::TReqReadJournalPtr request);

////////////////////////////////////////////////////////////////////////////////

} // namespace NYT::NApi::NRpcProxy

