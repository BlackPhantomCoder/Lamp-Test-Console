#pragma once
#include "Arduino.h"
#include "Data/CharArray.h"
#include "Types/Types.h"
#include "Types/ProgramTypes.h"

//get arg by symbol-terminator from str with remove 
CharArrayConstView get_argby_ref(CharArrayConstView& str, char symbol = ',');
//get arg by symbol-terminator from str
CharArrayConstView get_argby(CharArrayConstView str, char symbol = ',');

//char to  operations
inline operations get_operation(char val) {return operations(val);}
//types to data_type
inline data_type types_to_dtype(types type) {return data_type(type);}
//char to types
inline types get_types(char val) {return types(val);}
//char to exdata_type
inline exdata_type get_exdtype(char val) {return exdata_type(val);}

//read exdata_type from CharArrayConstView
exdata_type get_exdtype_ref(CharArrayConstView& arg);
//read byte from CharArrayConstView with remove 2 bytes [str: exdata_type, byte]
::byte read_byte_ref(CharArrayConstView& arg);
//read dbyte from CharArrayConstView with remove 3 bytes [str: exdata_type, byte, byte]
dbyte read_dbyte_ref(CharArrayConstView& arg);
//read num(byte/dbyte) from CharArrayConstView [str: exdata_type, byte]/[str: exdata_type, byte, byte]
dbyte read_num(CharArrayConstView arg);
//read num(byte/dbyte) from CharArrayConstView with remove 2/3 bytes [str: exdata_type, byte]/[str: exdata_type, byte, byte]
dbyte read_num_ref(CharArrayConstView& arg);
