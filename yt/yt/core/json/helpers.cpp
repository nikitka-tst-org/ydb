#include "helpers.h"

namespace NYT::NJson {

////////////////////////////////////////////////////////////////////////////////

bool IsSpecialJsonKey(TStringBuf key)
{
    return key.size() > 0 && key[0] == '$';
}

////////////////////////////////////////////////////////////////////////////////

} // namespace NYT::NJson
