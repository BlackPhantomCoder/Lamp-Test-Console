#pragma once
#include "Arduino.h"
#include "Types/Types.h"
#include "Array.h"
#include "Program.h"

class TypeController {
public:
	TypeController(TypeController&&) = default;
	TypeController(const TypeController&) = default;
	TypeController(::byte size_l, ::byte size_b, ::byte size_db);

	void set(const pair<data_type, ::byte>& t_and_a, dbyte val);
	dbyte get(const pair<data_type, ::byte>& t_and_a)const;
private:
	Array<bool, ::byte> t_bool;
	Array<::byte, ::byte> t_byte;
	Array<dbyte, ::byte> t_dbyte;
};

TypeController make_TypeController(Program& p);
