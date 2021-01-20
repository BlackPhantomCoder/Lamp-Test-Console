#pragma once
#include "Arduino.h"
#include "Data/CharArray.h"
#include "RAM.h"
#include "Funcs/ExternalFuncs.h"
#include "Types/ProcedureCallTypes.h"

//Commands Executer
class CmdExecuter {
public:
	CmdExecuter(const CmdExecuter&) = default;
	CmdExecuter(RAM& ram, ExternalFuncs& ex_fnc, call_procedure_fnc call_fnc);
	~CmdExecuter() = default;

	CmdExecuter& operator=(const CmdExecuter&) = default;

	//commad::set fnc
	void set(CharArrayConstView args);
	//commad::swap fnc
	void swap(CharArrayConstView args);
	//commad::random fnc
	void random(CharArrayConstView args);

	//commad::cset fnc
	void cset(CharArrayConstView args);
	//commad::ccopy fnc
	void ccopy(CharArrayConstView args);
	//commad::cswap fnc
	void cswap(CharArrayConstView args);
	//commad::ccopyall fnc
	void ccopyall(CharArrayConstView args);
	//commad::cclear fnc
	void cclear();

	//commad::draw fnc
	void draw();
	//commad::pause fnc
	void pause(CharArrayConstView args);
	//commad::update fnc
	void update();
	//commad::call_procedure fnc
	Procedure* call_procedure(CharArrayConstView args);
private:
	//Memory container
	RAM& t_ram;
	//ExternalFuncs container
	ExternalFuncs& t_ex_funcs;
	//procedure call fnc
	call_procedure_fnc t_call;
};