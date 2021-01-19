#pragma once
#include "Arduino.h"
#include "Types/Types.h"
#include "Data/CharArray.h"
#include "ReadFile.h"
#include "Types/ProgramTypes.h"

class Program {
public:
	Program(ReadFile& f);
	void skip(dbyte count);
	dbyte get_next_pos();
	void set_next_pos(dbyte pos);
	void set_start(dbyte pos);
	command skip_cmd();
	command peek_cmd();
	pair<command, CharArray> get_cmd();
	void get_cmd(command& ccmd, CharArray& args);

	const String& get_name()const;
private:
	command t_read_cmd();
	::byte t_read_args_size();
private:
	ReadFile& t_file;
	dbyte t_start;
};