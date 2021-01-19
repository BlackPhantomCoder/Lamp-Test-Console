#pragma once
#include "Arduino.h"
#include "Types/Types.h"
#include "Data/CharArray.h"
#include "RAM.h"
#include "Program.h"
#include "Funcs/ExternalFuncs.h"
#include "Types/ProcedureCallTypes.h"
#include "Executer.h"
#include "Types/ProgramTypes.h"

class Procedure {
public:
	Procedure(Program& program, const RAM& ram, ExternalFuncs& ex_funcs, call_procedure_fnc call_fnc);
	~Procedure();

	command update();
	void stop();
	void reset();
private:
	enum class processor_type
	{
		simple_processor,
		if_processor,
		for_processor,
		while_processor
	};
private:
	bool t_is_stop();
	pair<bool, command> try_another(command cmd, processor_type type);
	command t_execute();
	void t_simple_process(command cmd);
	command t_if_process();
	command t_for_process();
	command t_while_process();
private:
	Program& t_program;
	RAM t_ram;
	CmdExecuter t_executer;
	bool t_stop;
	CharArray t_args_container;
	CharArrayView t_args;
	dbyte t_begin;
	pair<Procedure*, dbyte> t_sub_procedure;
};