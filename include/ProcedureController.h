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

using ProcedureArray = Array<procedure_info, ::byte>;
class ProcedureController {
public:
	ProcedureController(const ProcedureArray& procedures, LedsController32& core, const ExternalFuncs& ex_funcs, Program& program);
	~ProcedureController() = default;
	::byte count();
	Procedure* call_procedure(::byte id, CharArrayView args, const ArgsArray& values, call_procedure_fnc fnc);
private:
	ProcedureArray t_procedures;
	LedsController32& t_core;
	Program& t_program;
	ExternalFuncs t_ex_funcs;
	dbyte t_offset;
};

ProcedureController make_ProcedureController(Program& program, LedsController32& core, const ExternalFuncs& ex_funcs);