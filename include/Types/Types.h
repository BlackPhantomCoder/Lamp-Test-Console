#pragma once
#include "Arduino.h"

using dbyte = unsigned;

template <class A, class B>
struct pair {
	pair(const A& a = A(), const B& b = B()) : first(a), second(b) {}
	A first;
	B second;
};