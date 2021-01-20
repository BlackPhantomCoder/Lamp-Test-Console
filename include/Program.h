#pragma once
#include "Arduino.h"
#include "Types/Types.h"
#include "Data/CharArray.h"
#include "ReadFile.h"
#include "Types/ProgramTypes.h"

//Reads commands and args from file
class Program {
public:
	Program(Program&&) = default;
	Program(const Program&) = delete;

	Program(ReadFile& f);
	~Program() = default;

	Program& operator=(const Program&) = delete;

	//skip count bytes
	void skip(dbyte count);
	//get next filepos
	dbyte get_next_pos();
	//set next filepos
	void set_next_pos(dbyte pos);
	//set start filepos
	void set_start(dbyte pos);
	//skip command and args
	command skip_cmd();
	//peek command and args
	command peek_cmd();
	//read command and args
	pair<command, CharArray> get_cmd();
	//read command and args
	void get_cmd(command& cmd, CharArray& args);
private:
	command t_read_cmd();
	::byte t_read_args_size();
private:
	//file
	ReadFile& t_file;
	//start pos
	dbyte t_start;
};