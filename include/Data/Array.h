#pragma once
#include "Iterators.h"

//Fixed dynamic array
template <class T, class size_type>
class Array {
public:
    Array(Array&& rh)noexcept;
    Array(const Array& rh);

    Array();
    Array(size_type size);
    ~Array();

    Array& operator=(const Array& rh);

    //access to data array
    T& operator[](size_type pos);
    T operator[](size_type pos)const;
    //size of array
    size_type size() const;
    //clear array (delete data, size = 0)
    void clear();

    //iterators
    PtrIterator<T, size_type> begin();
    PtrIterator<T, size_type> end();
  
    //const_iterators
    ConstPtrIterator<T, size_type> begin() const;
    ConstPtrIterator<T, size_type> end() const;
private:
    //size
    size_type t_size;
    //data array
    T* t_data;
};










template<class T, class size_type>
inline Array<T, size_type>::Array(Array&& rh) noexcept:
    t_size(rh.t_size),
    t_data(rh.t_data)
{
    rh.t_data = nullptr;
    rh.t_size = 0;
}

template<class T, class size_type>
inline Array<T, size_type>::Array(const Array& rh) :
    Array(rh.t_size) 
{
    for (size_type i = 0; i < t_size; ++i) {
        t_data[i] = rh.t_data[i];
    }
}

template<class T, class size_type>
inline Array<T, size_type>::Array():
    t_size(0),
    t_data(nullptr) 
{}

template<class T, class size_type>
inline Array<T, size_type>::Array(size_type size):
    t_size(size),
    t_data(new T[size])
{}

template<class T, class size_type>
inline Array<T, size_type>::~Array()
{
    delete t_data; 
    t_data = nullptr;
    t_size = 0;
}

template<class T, class size_type>
inline Array<T, size_type>& Array<T, size_type>::operator=(const Array& rh)
{
    if (&rh == this)return *this;
    delete t_data;
    t_size = rh.t_size;
    t_data = new T[rh.t_size];
    for (size_type i = 0; i < t_size; ++i) {
        t_data[i] = rh.t_data[i];
    }
    return *this;
}

template<class T, class size_type>
inline T& Array<T, size_type>::operator[](size_type pos)
{
    return t_data[pos];
}

template<class T, class size_type>
inline T Array<T, size_type>::operator[](size_type pos) const
{
    return t_data[pos];
}

template<class T, class size_type>
inline size_type Array<T, size_type>::size() const
{
    return t_size;
}

template<class T, class size_type>
inline void Array<T, size_type>::clear()
{
    delete t_data;
    t_data = nullptr;
    t_size = 0;
}

template<class T, class size_type>
inline PtrIterator<T, size_type> Array<T, size_type>::begin()
{
    return  { t_data, 0 };
}

template<class T, class size_type>
inline PtrIterator<T, size_type> Array<T, size_type>::end()
{
    return { t_data, t_size };
}

template<class T, class size_type>
inline ConstPtrIterator<T, size_type> Array<T, size_type>::begin() const
{
    return { t_data, 0 };
}

template<class T, class size_type>
inline ConstPtrIterator<T, size_type> Array<T, size_type>::end() const
{
    return { t_data, t_size };
}