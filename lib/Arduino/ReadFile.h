#pragma once
#include "Arduino.h"
#include <fstream>

//Emulating Simple File Interface
class ReadFile {
public:
	ReadFile(const ReadFile&) = delete;
	ReadFile(ReadFile&& rh)noexcept = default;

	ReadFile(std::ifstream& data, const String& filename);

	ReadFile& operator=(const ReadFile&) = delete;

	//seek
	void seek(unsigned long pos);
	//tell
	unsigned long tell();
	//get name
	const String& get_name()const;
	//read byte
	char read();
private:
	String t_name;
	std::ifstream& t_data;
	std::streampos t_size;
};