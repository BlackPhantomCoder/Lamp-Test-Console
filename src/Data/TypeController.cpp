#include "Data/TypeController.h"
#include "Funcs/Funcs.h"

TypeController::TypeController(::byte size_l, ::byte size_b, ::byte size_db) :
    t_bool(size_l),
    t_byte(size_b),
    t_dbyte(size_db)
{
}

void TypeController::set(const pair<data_type, ::byte>& t_and_a, dbyte val)
{
    switch (t_and_a.first)
    {
    case  data_type::B:
        t_byte[t_and_a.second] = static_cast<byte>(val);
        break;
    case  data_type::DB:
        t_dbyte[t_and_a.second] = val;
        break;
    case  data_type::L:
        t_bool[t_and_a.second] = static_cast<bool>(val);
        break;
    }
}

dbyte TypeController::get(const pair<data_type, ::byte>& t_and_a)const
{
    switch (t_and_a.first)
    {
    case data_type::B:
        return t_byte[t_and_a.second];
        break;
    case  data_type::DB:
        return t_dbyte[t_and_a.second];
        break;
    case  data_type::L:
        return t_bool[t_and_a.second];
        break;
    }
    return 0;
}

TypeController make_TypeController(Program& p)
{
    ::byte log_size = 0, byte_size = 0, dbyte_size = 0;
    if (p.peek_cmd() == command::var) {
        p.skip_cmd();

        auto cmd_pair = p.get_cmd();
        while (cmd_pair.first != command::evar) {
            switch (cmd_pair.first)
            {
            case  command::byte_:
                byte_size = static_cast<byte>(read_num(CharArrayConstView(cmd_pair.second)));
                break;
            case  command::dbyte_:
                dbyte_size = static_cast<byte>(read_num(CharArrayConstView(cmd_pair.second)));
                break;
            case  command::bool_:
                log_size = static_cast<byte>(read_num(CharArrayConstView(cmd_pair.second)));
                break;
            }
            cmd_pair = p.get_cmd();
        }
    }
    return TypeController(log_size, byte_size, dbyte_size);
}