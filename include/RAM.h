#pragma once
#include "Arduino.h"
#include "Types/Types.h"
#include "LedsController.h"
#include "Program.h"
#include "Data/TypeController.h"
#include "Types/ProgramTypes.h"
#include "Data/CharArray.h"

class RAM{
public:
	RAM(RAM&&) = default;
	RAM(const RAM&) = default;
	RAM(const TypeController & vars, LedsController32 & leds);

	pair<exdata_type, ::byte> get_type_and_adress(CharArrayView arg) const;
	dbyte solve_val(CharArrayView arg) const;
	dbyte read_val(const pair<exdata_type, ::byte> & t_and_a)const;
	dbyte get_val(CharArrayView arg)const;
	const LedsController32& get_leds()const;

	void set_val(const pair<exdata_type, ::byte> & t_and_a, dbyte val);
	LedsController32& get_leds();
private:
	TypeController t_vars;
	LedsController32& t_leds;
};