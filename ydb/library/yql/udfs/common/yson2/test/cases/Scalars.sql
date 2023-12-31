/* syntax version 1 */
$no_strict = Yson::Options(false AS Strict);

select
Yson::ConvertToBool(Yson::Parse('#'), $no_strict),
Yson::ConvertToBool(Yson::Parse('%true')),
Yson::ConvertToBool(Yson::Parse('true')),
Yson::ConvertToBool(Yson::Parse('false')),
Yson::ConvertToBool(Yson::Parse('1'), $no_strict),
Yson::ConvertToBool(Yson::Parse('2u'), $no_strict),
Yson::ConvertToBool(Yson::Parse('3.0'), $no_strict),
Yson::ConvertToBool(Yson::Parse('foo'), $no_strict),
Yson::ConvertToBool(Yson::Parse('"very loooooooooooooooooong string"'), $no_strict),

Yson::ConvertToInt64(Yson::Parse('#'), $no_strict),
Yson::ConvertToInt64(Yson::Parse('%true'), $no_strict),
Yson::ConvertToInt64(Yson::Parse('1')),
Yson::ConvertToInt64(Yson::Parse('2u')),
Yson::ConvertToInt64(Yson::Parse('3.0'), $no_strict),
Yson::ConvertToInt64(Yson::Parse('foo'), $no_strict),
Yson::ConvertToInt64(Yson::Parse('"very loooooooooooooooooong string"'), $no_strict),

Yson::ConvertToUint64(Yson::Parse('#'), $no_strict),
Yson::ConvertToUint64(Yson::Parse('%true'), $no_strict),
Yson::ConvertToUint64(Yson::Parse('-1'), $no_strict),
Yson::ConvertToUint64(Yson::Parse('1')),
Yson::ConvertToUint64(Yson::Parse('2u')),
Yson::ConvertToUint64(Yson::Parse('3.0'), $no_strict),
Yson::ConvertToUint64(Yson::Parse('foo'), $no_strict),
Yson::ConvertToUint64(Yson::Parse('"very loooooooooooooooooong string"'), $no_strict),

Yson::ConvertToDouble(Yson::Parse('#'), $no_strict),
Yson::ConvertToDouble(Yson::Parse('%true'), $no_strict),
Yson::ConvertToDouble(Yson::Parse('1')),
Yson::ConvertToDouble(Yson::Parse('2u')),
Yson::ConvertToDouble(Yson::Parse('3.0')),
Yson::ConvertToDouble(Yson::Parse('foo'), $no_strict),
Yson::ConvertToDouble(Yson::Parse('"very loooooooooooooooooong string"'), $no_strict),

Yson::ConvertToString(Yson::Parse('#'), $no_strict),
Yson::ConvertToString(Yson::Parse('%true'), $no_strict),
Yson::ConvertToString(Yson::Parse('1'), $no_strict),
Yson::ConvertToString(Yson::Parse('2u'), $no_strict),
Yson::ConvertToString(Yson::Parse('3.0'), $no_strict),
Yson::ConvertToString(Yson::Parse('foo')),
Yson::ConvertToString(Yson::Parse('"very loooooooooooooooooong string"')),
