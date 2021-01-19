#include "Procedure.h"
#include "Funcs/Funcs.h"
#include "Types/ProcedureCallTypes.h"

Procedure::Procedure(Program& program, const RAM& ram, ExternalFuncs& ex_funcs, call_procedure_fnc call_fnc) :
    t_program(program),
    t_ram(ram),
    t_executer(t_ram, ex_funcs, call_fnc),
    t_stop(false),
    t_args_container(0),
    t_args(t_args_container),
    t_begin(program.get_next_pos()),
    t_sub_procedure({ nullptr, 0 })
{
}

Procedure::~Procedure()
{
    if (t_sub_procedure.first) {
        delete t_sub_procedure.first;
        t_sub_procedure.first = nullptr;
    }
    t_stop = true;

}

command Procedure::update()
{
    if (t_stop) return command::stop;
    return t_execute();
}

void Procedure::stop()
{
    t_stop = true;
    if (t_sub_procedure.first)t_sub_procedure.first->stop();
}

void Procedure::reset()
{
    t_program.set_next_pos(t_begin);
}

bool Procedure::t_is_stop()
{
    return t_stop;
}

pair<bool, command> Procedure::try_another(command cmd, processor_type type)
{
    switch (cmd)
    {
    case command::if_:
        if (type == processor_type::if_processor)return { false,  command::nop };
        cmd = t_if_process();
        break;
    case command::for_:
        if (type == processor_type::for_processor)return { false, command::nop };
        cmd = t_for_process();
        break;
    case command::while_:
        if (type == processor_type::while_processor)return { false, command::nop };
        cmd = t_while_process();
        break;
    default:
        if (type == processor_type::simple_processor)return { false, command::nop };
        t_simple_process(cmd);
        break;
    }
    return { true, cmd };

}

command Procedure::t_execute()
{
    if (t_sub_procedure.first) {
        command result = t_sub_procedure.first->update();
        if (result == command::end_procedure) {
            delete t_sub_procedure.first;
            t_sub_procedure.first = nullptr;

            t_program.set_next_pos(t_sub_procedure.second);
            return command::nop;
        }
        return result;
    }
    t_executer.update();
    command cmd = command::nop;
    t_program.get_cmd(cmd, t_args_container);
    t_args = CharArrayView(t_args_container);
    auto try_result = try_another(cmd, processor_type::simple_processor);
    if (!try_result.first) {
        t_simple_process(cmd);
        return cmd;
    }
    return try_result.second;
}


command Procedure::t_for_process()
{
    auto t_and_a = t_ram.get_type_and_adress(get_argby_ref(t_args));
    auto beg_val = t_ram.get_val(get_argby_ref(t_args));
    auto end_val = t_ram.get_val(get_argby_ref(t_args));

    t_ram.set_val(t_and_a, beg_val);

    auto cmd = command::for_;
    auto pos = t_program.get_next_pos();
    for (;
        t_ram.read_val(t_and_a) <= end_val && !t_is_stop();
        t_ram.set_val(t_and_a, t_ram.read_val(t_and_a) + 1)
        )
    {
        t_program.set_next_pos(pos);
        while ((((cmd = t_execute()) != command::efor) && !t_is_stop())) {}
    }

    return cmd;
}

command Procedure::t_while_process()
{
    auto t_and_a = t_ram.get_type_and_adress(get_argby_ref(t_args));
    auto cmd = command::while_;
    auto pos = t_program.get_next_pos();
    while (t_ram.read_val(t_and_a) && !t_is_stop())
    {
        t_program.set_next_pos(pos);
        while ((((cmd = t_execute()) != command::ewhile) && !t_is_stop())) {}
    }

    return cmd;
}

command Procedure::t_if_process()
{
    auto condition = false;
    dbyte skip_count = 0;
    {
        auto l_val = t_ram.get_val(get_argby_ref(t_args));
        auto op = get_argby_ref(t_args)[0];
        auto r_val = t_ram.get_val(get_argby_ref(t_args));

        switch (op)
        {
        case '>':
            condition = l_val > r_val;
            break;
        case '<':
            condition = l_val < r_val;
            break;
        case '=':
            condition = l_val == r_val;
            break;
        }
        skip_count = t_ram.get_val(t_args);
    }


    auto cmd = command::if_;
    if (condition) {
        auto pos = t_program.get_next_pos() + skip_count;
        cmd = t_execute();
        while (t_program.get_next_pos() != pos && !t_is_stop()) {
            cmd = t_execute();
        }

        if (t_program.peek_cmd() == command::else_) {
            auto args = t_program.get_cmd().second;
            skip_count = t_ram.get_val(CharArrayView(args));
            t_program.skip(skip_count);
        }
    }
    else {
        t_program.skip(skip_count);
        if (t_program.peek_cmd() == command::else_) {
            auto args = t_program.get_cmd().second;
            skip_count = t_ram.get_val(CharArrayView(args));
            auto pos = t_program.get_next_pos() + skip_count;
            while (t_program.get_next_pos() != pos && !t_is_stop()) {
                cmd = t_execute();
            }
        }
    }

    return cmd;
}

void Procedure::t_simple_process(command cmd)
{
    switch (cmd)
    {
    case  command::set:
        t_executer.set(t_args);
        break;
    case  command::swap:
        t_executer.swap(t_args);
        break;
    case  command::random:
        t_executer.random(t_args);
        break;

    case  command::pause:
        t_executer.pause(t_args);
        break;
    case  command::draw:
        t_executer.draw();
        break;

    case  command::cset:
        t_executer.cset(t_args);
        break;
    case  command::ccopy:
        t_executer.ccopy(t_args);
        break;
    case  command::cswap:
        t_executer.cswap(t_args);
        break;
    case  command::ccopyall:
        t_executer.ccopyall(t_args);
        break;

    case  command::procedure_call: 
        {
            auto pos = t_program.get_next_pos();
            t_sub_procedure = { t_executer.call_procedure(t_args), pos };
        }
        break;
    }
}