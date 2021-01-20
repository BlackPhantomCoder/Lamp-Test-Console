#pragma once
#include "Arduino.h"
#include "Types/Types.h"
#include "Data/CharArray.h"

struct procedure_info {
	::byte args_count = 0;
	dbyte pos = 0;
};

using ArgsArray = Array<dbyte, ::byte>;
class Procedure;
struct CallProcedureInt {
	virtual Procedure* operator() (::byte, CharArrayConstView, const ArgsArray&) = 0;
};

class CallProcedureFnc {
public:
	CallProcedureFnc(CallProcedureInt& cpi);
	Procedure* operator() (::byte id, CharArrayConstView args, const ArgsArray& args_arr);
private:
	CallProcedureInt& t_cpi;
};

using call_procedure_fnc = CallProcedureFnc;