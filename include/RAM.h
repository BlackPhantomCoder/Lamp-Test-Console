#pragma once
#include "Arduino.h"
#include "Types/Types.h"
#include "LedsController.h"
#include "Program.h"
#include "Data/TypeController.h"
#include "Types/ProgramTypes.h"
#include "Data/CharArray.h"

//exdata_type + id
using exdata_pair = pair<exdata_type, ::byte>;

//A set of functions for interacting with TypeController, LedsController32
class RAM {
public:
	RAM(const RAM&) = default;

	RAM(const TypeController & vars, LedsController32 & leds);

	RAM& operator=(const RAM&) = default;

	//get exdata_pair by args
	exdata_pair get_type_and_adress(CharArrayConstView arg) const;
	//get val by expression
	dbyte solve_val(CharArrayConstView arg) const;
	//get val by exdata_pair
	dbyte read_val(const exdata_pair& t_and_a)const;
	//get val by args
	dbyte get_val(CharArrayConstView arg)const;
	//set val of var/led by  exdata_pair
	void set_val(const exdata_pair& t_and_a, dbyte val);
	//get leds
	LedsController32& get_leds();
private:
	//vars 
	TypeController t_vars;
	//leds
	LedsController32& t_leds;
};