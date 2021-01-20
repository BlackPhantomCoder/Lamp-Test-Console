#include "Program.h"

Program::Program(ReadFile& f):
	t_file(f),
	t_start(static_cast<dbyte>(f.tell()))
{}

void Program::skip(dbyte count)
{
    set_next_pos(get_next_pos() + count);
}

dbyte Program::get_next_pos()
{
    return static_cast<dbyte>(t_file.tell());
}

void Program::set_next_pos(dbyte pos)
{
    t_file.seek(pos);
}

void Program::set_start(dbyte pos)
{
    t_start = pos;
}

command Program::skip_cmd()
{
    const auto result = t_read_cmd();
    skip(t_read_args_size());
    return result;
}

command Program::peek_cmd()
{
    auto pos = get_next_pos();
    const auto cmd = t_read_cmd();
    set_next_pos(pos);
    return	cmd;
}

pair<command, CharArray> Program::get_cmd()
{
    const auto cmd = t_read_cmd();
    const auto count = t_read_args_size();
    CharArray args(count);
    for (::byte i = 0; i < count; ++i) {
        args[i] = t_file.read();
    }
    return { cmd, args };
}

void Program::get_cmd(command& cmd, CharArray& args)
{
    cmd = t_read_cmd();
    const auto count = t_read_args_size();
    args = CharArray(count);
    for (::byte i = 0; i < count; ++i) {
        args[i] = t_file.read();
    }
}

command Program::t_read_cmd()
{
    return static_cast<command>(t_file.read());
}

::byte Program::t_read_args_size() {
    return t_file.read();
}