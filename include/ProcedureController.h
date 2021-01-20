#pragma once
#include "Arduino.h"
#include "Types/Types.h"
#include "Data/Array.h"
#include "Data/CharArray.h"
#include "LedsController.h"
#include "Program.h"
#include "Funcs/ExternalFuncs.h"
#include "Procedure.h"
#include "Types/ProcedureCallTypes.h"

//Array of procedure_info
using ProcedureArray = Array<procedure_info, ::byte>;

//Creating procedures from procedure table
class ProcedureController {
public:
	ProcedureController(ProcedureController&&) = default;
	ProcedureController(const ProcedureController&) = delete;

	ProcedureController(const ProcedureArray& procedures, LedsController32& core, const ExternalFuncs& ex_funcs, Program& program);
	~ProcedureController() = default;

	ProcedureController& operator=(const ProcedureController&) = delete;

	//count of procedures
	::byte count()const;
	//creates procedure from procedure table by id,
	//copies values to RAM (var adress from args)
	Procedure* call_procedure(::byte id, CharArrayConstView args, const ArgsArray& values, call_procedure_fnc fnc);
private:
	//Procedure info
	ProcedureArray t_procedures;
	//Leds
	LedsController32& t_core;
	//Program
	Program& t_program;
	//Ex funcs
	ExternalFuncs t_ex_funcs;
	//offset from begin of the program
	dbyte t_offset;
};


//Reads the procedure table, creates ProcedureController
ProcedureController make_ProcedureController(Program& program, LedsController32& core, const ExternalFuncs& ex_funcs);