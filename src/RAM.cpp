#include "RAM.h"

#include "Funcs/Funcs.h"
#include "Data/Stack.h"

RAM::RAM(const TypeController& vars, LedsController32& leds) :
    t_vars(vars),
    t_leds(leds)
{}

pair<exdata_type, ::byte> RAM::get_type_and_adress(CharArrayView arg) const
{
    auto type = get_exdtype_ref(arg);
    ::byte i = 0;

    while (get_types(arg[i]) != types::E && get_types(arg[i]) != types::NUM_BYTE && get_types(arg[i]) != types::NUM_DBYTE) {
        ++i;
    }

    ::byte adress = 0;
    {
        auto buf = arg;
        buf.remove_beg(i);
        arg.remove_end(buf.size() - i);
        adress = get_val(buf);
    }

    while (arg.size() != 0) {
        adress = read_val({ get_exdtype(arg[arg.size() - 1]), adress });
    }
    return { type, adress };
}

dbyte RAM::solve_val(CharArrayView arg) const
{
    Stack<dbyte, ::byte> stack(read_num_ref(arg));
    while (arg.size() != 0) {
        auto size = read_byte_ref(arg);
        auto buf = arg;
        buf.remove_end(arg.size() - size);
        arg.remove_beg(size);
        if (get_types(buf[0]) == types::OP) {
            auto right = stack.pop();
            auto left = stack.pop();
            dbyte result = 0;
            switch (get_operation(buf[1]))
            {
            case operations::plus:
                result = left + right;
                break;
            case operations::minus:
                result = left - right;
                break;
            case operations::pow:
                //not pow
                result = left ^ right;
                break;
            case operations::mlt:
                result = left * right;
                break;
            case operations::div:
                result = left / right;
                break;
            case operations::mod:
                result = left % right;
                break;
            }
            stack.push(result);
        }
        else {
            stack.push(get_val(buf));
        }

    }
    return stack.pop();
}

dbyte RAM::read_val(const pair<exdata_type, ::byte>& t_and_a) const
{
    switch (t_and_a.first)
    {
    case exdata_type::B:
    case exdata_type::DB:
    case exdata_type::L:
        return t_vars.get({ data_type(t_and_a.first), t_and_a.second });
        break;
    case exdata_type::CR:
        return t_leds.get(t_and_a.second).red;
        break;
    case exdata_type::CB:
        return t_leds.get(t_and_a.second).blue;
        break;
    case exdata_type::CG:
        return t_leds.get(t_and_a.second).green;
        break;
    }
    return 0;
}

void RAM::set_val(const pair<exdata_type, ::byte>& t_and_a, dbyte val)
{
    switch (t_and_a.first)
    {
    case exdata_type::B:
    case exdata_type::DB:
    case exdata_type::L:
        t_vars.set({ data_type(t_and_a.first), t_and_a.second }, val);
        break;
    case exdata_type::CR:
        t_leds.set(t_and_a.second, val, LedsController32::red);
        break;
    case exdata_type::CB:
        t_leds.set(t_and_a.second, val, LedsController32::blue);
        break;
    case exdata_type::CG:
        t_leds.set(t_and_a.second, val, LedsController32::green);
        break;
    }
}

dbyte RAM::get_val(CharArrayView arg) const
{
    auto type = get_types(arg[0]);
    switch (type)
    {
    case types::E:
        arg.remove_beg(1);
        return solve_val(arg);
        break;
    case types::NUM_BYTE:
        return read_byte_ref(arg);
        break;
    case types::NUM_DBYTE:
        return read_dbyte_ref(arg);
        break;
    default:
        return read_val(get_type_and_adress(arg));
        break;
    }
}

const LedsController32& RAM::get_leds() const
{
    return t_leds;
}

LedsController32& RAM::get_leds()
{
    return t_leds;
}