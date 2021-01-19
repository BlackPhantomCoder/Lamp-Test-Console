#pragma once

template <class T, class size_type>
class Stack
{
public:
	Stack(::byte max_size) : t_size(0), t_max_size(max_size), t_data(new T[max_size]) {}
	Stack(const Stack& rh) {
		delete t_data;
		t_size = rh.t_size;
		t_max_size = rh.t_max_size;
		t_data = new T[t_max_size];
		for (size_type i = 0; i < t_size; ++i) t_data[i] = rh.t_data[i];
	}
	~Stack() {
		delete t_data;
		t_size = 0;
		t_max_size = 0;
	}
	const T& top() const { return t_data[t_size - 1]; }
	T& top() { return t_data[t_size - 1]; }
	T& pop() { return t_data[--t_size]; }
	void push(const T& val) { t_data[t_size++] = val; }
	bool empty()const { return t_size == 0; }
	size_type size() const { return t_size; }

private:
	T* t_data;
	size_type t_size;
	size_type t_max_size;
};