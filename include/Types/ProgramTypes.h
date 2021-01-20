#pragma once
#include "Arduino.h"
#include "Types/Types.h"

//
enum class types {
	BYTE = 0,
	DBYTE,
	LOG,
	CG,
	CR,
	CB,
	E,
	OP,
	NUM_BYTE,
	NUM_DBYTE
};

//operations
enum class operations {
	// +
	plus = 0,
	// -
	minus,
	// ^
	pow,
	// *
	mlt,
	// /
	div,
	// %
	mod
};

//update fnc type
typedef void(*up_fnc)();
//draw fnc type
typedef void(*disp_up_fnc)();
//pause fnc type
typedef void(*pause_fnc)(dbyte);


//command constants
namespace commands {
	// 9-13,  - not in use
	enum command : uint8_t {
		//begin of var block
		var = 0,
		//end of var block
		evar = 1,
		//begin of procedure block
		procedure = 2,
		//end of end_procedure block
		end_procedure = 3,

		/*commands*/
		//procedure call command
		procedure_call = 4,
		set = 5,
		swap = 6,
		random = 7,
		if_ = 8,
		for_ = 14,
		while_ = 15,
		pause = 16,
		draw = 17,
		eif = 18,
		else_ = 19,
		eelse = 20,
		efor = 21,
		ewhile = 22,

		//var types
		bool_ = 23,
		byte_ = 24,
		dbyte_ = 25,

		/*leds commands*/
		cset = 26,
		ccopy = 27,
		cswap = 28,
		ccopyall = 29,
		cclear = 30,

		//stop command
		stop = 254,
		//no operation command
		nop = 255,
	};
};
using commands::command;

//data types
enum class data_type : uint8_t {
	B = static_cast<uint8_t>(types::BYTE),
	DB = static_cast<uint8_t>(types::DBYTE),
	L = static_cast<uint8_t>(types::LOG)
};

//data types and leds types
enum class exdata_type : uint8_t {
	B = static_cast<uint8_t>(data_type::B),
	DB = static_cast<uint8_t>(data_type::DB),
	L = static_cast<uint8_t>(data_type::L),

	CR = static_cast<uint8_t>(types::CR),
	CB = static_cast<uint8_t>(types::CB),
	CG = static_cast<uint8_t>(types::CG)
};