#pragma once
#include "Arduino.h"
#include "Types/Types.h"
#include "ReadFile.h"
#include "LedsController.h"
#include "Funcs/ExternalFuncs.h"
#include "Program.h"
#include "Procedure.h"
#include "ProcedureController.h"
#include "Types/ProcedureCallTypes.h"
#include "Data/CharArray.h"

class LampController {
public:
	LampController(ReadFile& f, LedsController32& core, const ExternalFuncs& ex_funcs);
	~LampController();
	bool update();
	const String& get_name()const;
	void stop();
private:
	Program t_program;
	ProcedureController t_pr_controller;
	Procedure* t_main_procedure;

	class CallProcedureWController : public CallProcedureInt {
	public:
		CallProcedureWController(ProcedureController& controller);
		virtual Procedure* operator()(::byte id, CharArrayView args, const ArgsArray& args_arr) override;
	private:
		ProcedureController& t_controller;
	} t_proc_fnc;
};