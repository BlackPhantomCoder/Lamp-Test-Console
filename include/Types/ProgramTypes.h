#pragma once
#include "Arduino.h"
#include "Types/Types.h"

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

enum class operations {
	plus = 0,
	minus,
	pow,
	mlt,
	div,
	mod
};


typedef void(*up_fnc)();
typedef void(*disp_up_fnc)();
typedef void(*pause_fnc)(dbyte);


namespace commands {
	// 9-13,  - not in use
	enum command : uint8_t {
		var = 0,
		evar = 1,

		procedure = 2,
		end_procedure = 3,
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

		bool_ = 23,
		byte_ = 24,
		dbyte_ = 25,

		cset = 26,
		ccopy = 27,
		cswap = 28,
		ccopyall = 29,
		cclear = 30,


		stop = 254,
		nop = 255,
	};
};
using commands::command;



enum class data_type : uint8_t {
	B = static_cast<uint8_t>(types::BYTE),
	DB = static_cast<uint8_t>(types::DBYTE),
	L = static_cast<uint8_t>(types::LOG)
};

enum class exdata_type : uint8_t {
	B = static_cast<uint8_t>(data_type::B),
	DB = static_cast<uint8_t>(data_type::DB),
	L = static_cast<uint8_t>(data_type::L),
	CR = static_cast<uint8_t>(types::CR),
	CB = static_cast<uint8_t>(types::CB),
	CG = static_cast<uint8_t>(types::CG)
};