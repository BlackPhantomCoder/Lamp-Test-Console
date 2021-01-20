#include "Types/ProcedureCallTypes.h"

CallProcedureFnc::CallProcedureFnc(CallProcedureInt& cpi):
	t_cpi(cpi) 
	{}

Procedure* CallProcedureFnc::operator()(::byte id, CharArrayConstView args, const ArgsArray& args_arr)
{
	return t_cpi.operator()(id, args, args_arr);
}