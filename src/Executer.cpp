#include "Executer.h"
#include "Funcs/Funcs.h"
#include "Types/Types.h"

CmdExecuter::CmdExecuter(RAM& ram, ExternalFuncs& ex_fnc, call_procedure_fnc call_fnc) :
    t_ram(ram),
    t_ex_funcs(ex_fnc),
    t_call(call_fnc)
{}

void CmdExecuter::set(CharArrayConstView args)
{
    const auto cell = t_ram.get_type_and_adress(get_argby_ref(args));
    const auto val = t_ram.get_val(get_argby_ref(args));
    t_ram.set_val(cell, val);
}

void CmdExecuter::swap(CharArrayConstView args)
{
    const auto cell_1 = t_ram.get_type_and_adress(get_argby_ref(args));
    const auto cell_2 = t_ram.get_type_and_adress(get_argby_ref(args));

    const auto val_1 = t_ram.read_val(cell_1);
    t_ram.set_val(cell_1, t_ram.read_val(cell_2));
    t_ram.set_val(cell_2, val_1);
}

void CmdExecuter::random(CharArrayConstView args)
{
    const auto cell = t_ram.get_type_and_adress(get_argby_ref(args));
    const auto val_1 = t_ram.get_val(get_argby_ref(args));
    const auto val_2 = t_ram.get_val(get_argby_ref(args));
    t_ram.set_val(cell, ::random(val_1, val_2));
}

void CmdExecuter::cset(CharArrayConstView args)
{
    const auto cell = t_ram.get_val(get_argby_ref(args));
    const auto val_1 = t_ram.get_val(get_argby_ref(args));
    const auto val_2 = t_ram.get_val(get_argby_ref(args));
    const auto val_3 = t_ram.get_val(get_argby_ref(args));

    t_ram.get_leds().set(static_cast<byte>(cell), CRGB(static_cast<byte>(val_1), static_cast<byte>(val_2), static_cast<byte>(val_3)));
}

void CmdExecuter::ccopy(CharArrayConstView args)
{
    const auto cell_1 = t_ram.get_val(get_argby_ref(args));
    const auto cell_2 = t_ram.get_val(get_argby_ref(args));

    t_ram.get_leds().copy(static_cast<byte>(cell_1), static_cast<byte>(cell_2));
}

void CmdExecuter::cswap(CharArrayConstView args)
{
    const auto cell_1 = t_ram.get_val(get_argby_ref(args));
    const auto cell_2 = t_ram.get_val(get_argby_ref(args));
    t_ram.get_leds().swap(static_cast<byte>(cell_1), static_cast<byte>(cell_2));
}

void CmdExecuter::ccopyall(CharArrayConstView args)
{
    const auto val = static_cast<byte>(t_ram.get_val(get_argby_ref(args)));

    for (::byte i = 1; i < 4; ++i) {
        for (::byte j = 0; j < val; ++j) {
            t_ram.get_leds().copy(j + i * 8, j);
        }
    }
}

void CmdExecuter::cclear()
{
    t_ram.get_leds().clear();
}

void CmdExecuter::draw()
{
    t_ex_funcs.draw();
}

void CmdExecuter::pause(CharArrayConstView args)
{
    const auto val = t_ram.get_val(get_argby_ref(args));
    t_ex_funcs.pause(val);
}

void CmdExecuter::update()
{
    t_ex_funcs.update();
}

Procedure* CmdExecuter::call_procedure(CharArrayConstView args)
{
    const auto id = t_ram.get_val(get_argby_ref(args));
    const auto count = static_cast<byte>(t_ram.get_val(get_argby_ref(args)));
    ArgsArray args_arr(count);
    for (byte i = 0; i < count; ++i) {
        args_arr[i] = t_ram.get_val(get_argby_ref(args));
    }
    return t_call(static_cast<byte>(id), args, args_arr);
}