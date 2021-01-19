#include "LampController.h"

LampController::LampController(ReadFile& f, LedsController32& core, const ExternalFuncs& ex_funcs) :
    t_program(f),
    t_pr_controller(make_ProcedureController(t_program, core, ex_funcs)),
    t_proc_fnc(t_pr_controller),
    t_main_procedure(nullptr)
{
    if (t_pr_controller.count()) {
        auto empty_array = CharArray(0);
        t_main_procedure = t_pr_controller.call_procedure(0, CharArrayView(empty_array), ArgsArray(0), t_proc_fnc);
    }
    core.clear();
}

LampController::~LampController()
{
    if (t_main_procedure) delete t_main_procedure;
}

bool LampController::update()
{
    if (t_main_procedure) {
        auto result = t_main_procedure->update();
        if (result == command::end_procedure) {
            t_main_procedure->reset();
        }
        return result != command::stop;
    }
    return false;
}

const String& LampController::get_name()const {
    return t_program.get_name();
}

void LampController::stop()
{
    if (t_main_procedure) t_main_procedure->stop();
}

LampController::CallProcedureWController::CallProcedureWController(ProcedureController& controller): 
    t_controller(controller) 
    {}

Procedure* LampController::CallProcedureWController::operator()(::byte id, CharArrayView args, const ArgsArray& args_arr)
{
    return t_controller.call_procedure(id, args, args_arr, *this);
}
