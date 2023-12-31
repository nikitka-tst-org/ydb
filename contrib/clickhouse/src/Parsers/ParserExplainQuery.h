#pragma once

#include <Parsers/IParserBase.h>

namespace DB
{


class ParserExplainQuery : public IParserBase
{
protected:
    const char * end;
    bool allow_settings_after_format_in_insert;
    bool select_only;

    const char * getName() const override { return "EXPLAIN"; }
    bool parseImpl(Pos & pos, ASTPtr & node, Expected & expected) override;
public:
    explicit ParserExplainQuery(const char* end_, bool allow_settings_after_format_in_insert_)
        : end(end_)
        , allow_settings_after_format_in_insert(allow_settings_after_format_in_insert_)
        , select_only(false)
    {}

    explicit ParserExplainQuery()
        : end(nullptr) , allow_settings_after_format_in_insert(false) , select_only(true)
    {}

};

}
