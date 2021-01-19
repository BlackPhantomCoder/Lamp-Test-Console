#pragma once
#include "Arduino.h"
#include "Data/CharArray.h"
#include "Types/Types.h"
#include "Types/ProgramTypes.h"

inline types get_type_new(::byte ch) { return types(ch); }
inline dbyte to_dbyte_new(const CharArrayView& str) { return (dbyte(::byte(str[0])) << 8) + dbyte(::byte(str[1])); }
inline dbyte to_byte_new(const CharArrayView& str) { return str[0]; }
inline operations to_operation(::byte op){ return  operations(op); }

CharArrayView get_argby_ref(CharArrayView& str, char symbol = ',');
CharArrayView get_argby(CharArrayView str, char symbol = ',');
CharArrayView get_arg_ref(CharArrayView& str, ::byte offset);


inline operations get_operation(char val) {return operations(val);}
inline data_type types_to_dtype(types type) {return data_type(type);}
inline types get_types(char val) {return types(val);}
inline exdata_type get_exdtype(char val) {return exdata_type(val);}

types get_types_ref(CharArrayView& arg);
exdata_type get_exdtype_ref(CharArrayView& arg);
::byte read_byte_ref(CharArrayView& arg);
dbyte read_dbyte_ref(CharArrayView& arg);
dbyte read_num(CharArrayView arg);
dbyte read_num_ref(CharArrayView& arg);
