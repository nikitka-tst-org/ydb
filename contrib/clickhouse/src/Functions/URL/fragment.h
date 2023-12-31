#pragma once

#include <base/find_symbols.h>
#include <Functions/StringHelpers.h>

namespace DB
{

template <bool without_leading_char>
struct ExtractFragment
{
    static size_t getReserveLengthForElement() { return 10; }

    static void execute(Pos data, size_t size, Pos & res_data, size_t & res_size)
    {
        res_data = data;
        res_size = 0;

        Pos pos = data;
        Pos end = pos + size;

        if (end != (pos = find_first_symbols<'#'>(pos, end)))
        {
            res_data = pos + (without_leading_char ? 1 : 0);
            res_size = end - res_data;
        }
    }
};

}
