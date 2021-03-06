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

	//set val by data_type + id
	void set(const pair<data_type, ::byte>& t_and_a, dbyte val);
	//get val by data_type + id
	dbyte get(const pair<data_type, ::byte>& t_and_a)const;
private:
	//bool array
	Array<bool, ::byte> t_bool;
	//byte array
	Array<::byte, ::byte> t_byte;
	//dbyte array
	Array<dbyte, ::byte> t_dbyte;
};

//make fnc by program
TypeController make_TypeController(Program& p);
