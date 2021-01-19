#pragma once
typedef unsigned char byte;
#include <string>

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

unsigned random(unsigned a, unsigned b);
unsigned long millis();

#define F(x) x