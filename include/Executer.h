#pragma once
#include "Arduino.h"
#include "Data/CharArray.h"
#include "RAM.h"
#include "Funcs/ExternalFuncs.h"
#include "Types/ProcedureCallTypes.h"

class CmdExecuter {
public:
	CmdExecuter(RAM& ram, ExternalFuncs& ex_fnc, call_procedure_fnc call_fnc);

	void set(CharArrayView args);
	void swap(CharArrayView args);
	void random(CharArrayView args);

	void cset(CharArrayView args);
	void ccopy(CharArrayView args);
	void cswap(CharArrayView args);
	void ccopyall(CharArrayView args);
	void cclear();

	void draw();
	void pause(CharArrayView args);
	void update();
	Procedure* call_procedure(CharArrayView args);
private:
	RAM& t_ram;
	ExternalFuncs& t_ex_funcs;
	call_procedure_fnc t_call;
};