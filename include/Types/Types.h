#pragma once
#include "Arduino.h"

//unsigned 2 byte ty[e
using dbyte = uint16_t;

//pair of two types
template <class A, class B>
struct pair {
	pair(const A& a = A(), const B& b = B()) : first(a), second(b) {}
	A first;
	B second;
};