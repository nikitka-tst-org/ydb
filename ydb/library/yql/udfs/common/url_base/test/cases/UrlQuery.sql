SELECT
    value,
    Url::QueryStringToList(value, false AS Strict) AS base_list,
    Url::BuildQueryString(Url::QueryStringToList(value, false AS Strict)) AS base_list_build,
    Url::QueryStringToList(value, true AS KeepBlankValues, false AS Strict) AS keep_blank_list,
    Url::BuildQueryString(Url::QueryStringToList(value, true AS KeepBlankValues, false AS Strict)) AS keep_blank_list_build,
    Url::QueryStringToList(value, ";" AS Separator, false AS Strict) AS sep_semicol_list,
    Url::BuildQueryString(Url::QueryStringToList(value, ";" AS Separator, false AS Strict), ";" AS Separator) AS sep_semicol_list_build,
    Url::QueryStringToDict(value, false AS Strict) AS base_dict,
    Url::BuildQueryString(Url::QueryStringToDict(value, false AS Strict)) AS base_dict_build,
    Url::QueryStringToDict(value, true AS KeepBlankValues, false AS Strict) AS keep_blank_dict,
    Url::BuildQueryString(Url::QueryStringToDict(value, true AS KeepBlankValues, false AS Strict)) AS keep_blank_dict_build,
    Url::QueryStringToDict(value, ";" AS Separator, false AS Strict) AS sep_semicol_dict,
    Url::BuildQueryString(Url::QueryStringToDict(value, ";" AS Separator, false AS Strict), ";" AS Separator) AS sep_semicol_dict_build,
FROM Input;
