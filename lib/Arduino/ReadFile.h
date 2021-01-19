#pragma once
#include "Arduino.h"

#include <fstream>
class ReadFile {
public:
	ReadFile(std::ifstream& data, const String& filename) : t_data(data), t_name(filename) {
		t_data.seekg(0, std::ios::end);
		t_size = t_data.tellg();
		t_data.seekg(0, std::ios::beg);
	}
	void seek(unsigned long pos) {
		t_data.clear();
		t_data.seekg(pos);

	}
	unsigned long tell() {
		return static_cast<unsigned long>(t_data.tellg());
	}
	const String& get_name()const {
		return t_name;
	}
	unsigned long size()const {
		return static_cast<unsigned long>(t_size);
	}

	char read() {
		char result;
		t_data.read(&result, 1);
		return result;
	}
private:
	String t_name;
	std::ifstream& t_data;
	std::streampos t_size;
};