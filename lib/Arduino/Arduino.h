#pragma once
//Emulate Arduino byte
typedef unsigned char byte;
#include <string>

//Emulate Arduino String
class String : public std::string {
public:
	String(const std::string& str) : std::string(str) {};
	String(const char* ch = "") : std::string(ch) {}
	void remove(size_t pos) {
		this->erase(std::begin(*this) + pos);
	}
	void remove(size_t pos, size_t count) {
		this->erase(std::begin(*this) + pos, std::begin(*this) + pos + count);
	}
	size_t length()const {
		return this->size();
	}
};

//Emulate Arduino random
unsigned random(unsigned a, unsigned b);
//Emulate Arduino millis
unsigned long millis();
//Emulate Arduino F
#define F(x) x