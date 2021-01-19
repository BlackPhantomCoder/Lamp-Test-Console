#include "ProcedureController.h"

#include "Funcs/Funcs.h"
#include "RAM.h"

ProcedureController::ProcedureController(
    const ProcedureArray& procedures,
    LedsController32& core,
    const ExternalFuncs& ex_funcs,
    Program& program
)
    :
    t_procedures(procedures),
    t_core(core),
    t_program(program),
    t_ex_funcs(ex_funcs),
    t_offset(program.get_next_pos())
{
}

::byte ProcedureController::count()
{
    return t_procedures.size();
}

Procedure* ProcedureController::call_procedure(::byte id, CharArrayView args, const ArgsArray& values, call_procedure_fnc fnc)
{
    auto procedure_info = t_procedures[id];
    t_program.set_next_pos(procedure_info.pos);

    RAM ram(make_TypeController(t_program), t_core);

    for (auto val : values) {
        auto t_and_a = ram.get_type_and_adress(get_argby_ref(args));
        ram.set_val(t_and_a, val);
    }
    return new Procedure(t_program, ram, t_ex_funcs, fnc);
}

ProcedureController make_ProcedureController(Program& program, LedsController32& core, const ExternalFuncs& ex_funcs)
{
    auto cmd_pair = program.get_cmd();
    auto now_pos = program.get_next_pos();
    if (cmd_pair.first != command::procedure) {
        return ProcedureController(ProcedureArray(), core, ex_funcs, program);
    }
    else {
        auto args = CharArrayView(cmd_pair.second);

        RAM ram(TypeController(0, 0, 0), core);
        auto size = ram.get_val(get_argby_ref(args));
        ProcedureArray procedures(size);
        for (dbyte i = 0; i < size; ++i) {
            procedures[i].args_count = ram.get_val(get_argby_ref(args));
            procedures[i].pos = ram.get_val(get_argby_ref(args)) + now_pos;
        }

        return ProcedureController(procedures, core, ex_funcs, program);
    }
}