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

//Controller of LedsController32 by program written on The-Imperfect-Language
class LampController {
public:
	LampController(LampController&&) = default;
	LampController(const LampController& rh) = delete;

	LampController(ReadFile& f, LedsController32& core, const ExternalFuncs& ex_funcs);
	~LampController();

	LampController& operator=(const LampController& rh) = delete;

	//controll func, after stop() -> ends
	bool update();
	//stop LampController
	void stop();
private:
	//program
	Program t_program;
	//Controller Procedures
	ProcedureController t_pr_controller;
	//Main procedure
	Procedure* t_main_procedure;

	//realisation of procedure call mechanism
	class CallProcedureWController : public CallProcedureInt {
	public:
		CallProcedureWController(ProcedureController& controller);
		virtual Procedure* operator()(::byte id, CharArrayConstView args, const ArgsArray& args_arr) override;
	private:
		ProcedureController& t_controller;
	} 
	t_proc_fnc;
};