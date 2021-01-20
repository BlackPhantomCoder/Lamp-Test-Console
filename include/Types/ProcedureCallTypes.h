#pragma once
#include "Arduino.h"
#include "Types/Types.h"
#include "Data/CharArray.h"

//procedure ifo (args count and pos)
struct procedure_info {
	::byte args_count = 0;
	dbyte pos = 0;
};

//Array of args (dbyte)
using ArgsArray = Array<dbyte, ::byte>;

//Call Procedure Interface
class Procedure;
struct CallProcedureInt {
	virtual Procedure* operator() (::byte, CharArrayConstView, const ArgsArray&) = 0;
};

//Call Procedure Func
class CallProcedureFnc {
public:
	CallProcedureFnc(CallProcedureInt& cpi);
	Procedure* operator() (::byte id, CharArrayConstView args, const ArgsArray& args_arr);
private:
	CallProcedureInt& t_cpi;
};

//Call Procedure Func type
using call_procedure_fnc = CallProcedureFnc;