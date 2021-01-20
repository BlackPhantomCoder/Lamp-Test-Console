#include "Funcs/Funcs.h"

CharArrayConstView get_argby_ref(CharArrayConstView& str, char symbol)
{
    CharArrayConstView result(str);
    ::byte i = 0u;
    while (i != str.size() && str[i] != symbol) {
        ++i;
    }
    result.remove_end(str.size() - i);
    str.remove_beg((i != str.size()) ? i + 1 : i);
    return result;
}

CharArrayConstView get_argby(CharArrayConstView str, char symbol)
{
    CharArrayConstView result(str);
    ::byte i = 0u;
    while (i != str.size() && str[i] != symbol) {
        ++i;
    }
    result.remove_end(str.size() - i);
    return result;
}

CharArrayConstView get_arg_ref(CharArrayConstView& str, ::byte offset)
{
    CharArrayConstView result(str);
    result.remove_end(str.size() - offset);
    str.remove_beg(offset);
    return result;
}

types get_types_ref(CharArrayConstView& arg) {
    char result = arg[0];
    arg.remove_beg(1);
    return types(result);
}

exdata_type get_exdtype_ref(CharArrayConstView& arg) {
    char result = arg[0];
    arg.remove_beg(1);
    return exdata_type(result);
}

::byte read_byte_ref(CharArrayConstView& arg) {
    char l = arg[1];
    arg.remove_beg(2);
    return l;
}

dbyte read_dbyte_ref(CharArrayConstView& arg) {
    char h = arg[1];
    char l = arg[2];
    arg.remove_beg(3);
    return (h << 8) + l;
}

dbyte read_num(CharArrayConstView arg) {
    switch (get_types(arg[0]))
    {
    case types::NUM_BYTE:
        return read_byte_ref(arg);
        break;

    case types::NUM_DBYTE:
        return read_dbyte_ref(arg);
        break;
    default:
        return 0;
        break;
    }
}

dbyte read_num_ref(CharArrayConstView& arg) {
    switch (get_types(arg[0]))
    {
    case types::NUM_BYTE:
        return read_byte_ref(arg);
        break;

    case types::NUM_DBYTE:
        return read_dbyte_ref(arg);
        break;
    default:
        return 0;
        break;
    }
}