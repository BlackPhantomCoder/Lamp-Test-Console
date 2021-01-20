#pragma once
#include "Array.h"

//Stack(container - fixed dynamic array)
template <class T, class size_type>
class Stack
{
public:
	Stack(Stack&& rh) = default;
	Stack(const Stack&) = default;

	Stack(::byte max_size);
	~Stack() = default;

	Stack&  operator=(const Stack&) = default;

	//get top element
	T& top();
	const T& top() const;
	//delete top element
	T& pop();
	//push element
	void push(const T& val);
	//is empty
	bool empty()const;
	//size
	size_type size() const;
	//max_size
	size_type max_size() const;
private:
	//data array
	Array<T,size_type> t_data;
	//size
	size_type t_size;
};











template<class T, class size_type>
inline Stack<T, size_type>::Stack(::byte max_size):
	t_size(0),
	t_data(max_size)
{}

template<class T, class size_type>
inline const T& Stack<T, size_type>::top() const
{
	return t_data[t_size - 1];
}

template<class T, class size_type>
inline T& Stack<T, size_type>::top()
{
	return t_data[t_size - 1];
}

template<class T, class size_type>
inline T& Stack<T, size_type>::pop()
{
	return t_data[--t_size];
}

template<class T, class size_type>
inline void Stack<T, size_type>::push(const T& val)
{
	t_data[t_size++] = val;
}

template<class T, class size_type>
inline bool Stack<T, size_type>::empty() const
{
	return t_size == 0;
}

template<class T, class size_type>
inline size_type Stack<T, size_type>::size() const
{
	return t_size;
}

template<class T, class size_type>
inline size_type Stack<T, size_type>::max_size() const
{
	return t_data.size();
}
