#pragma once
#include "Iterators.h"

template <class T, class size_type>
class Array {
public:
    Array(Array&& rh)noexcept : t_size(rh.t_size), t_data(rh.t_data) {
        rh.t_data = nullptr;
        rh.t_size = 0;
    }
    Array(const Array& rh) : Array(rh.t_size) {
        for (size_type i = 0; i < t_size; ++i) {
            t_data[i] = rh.t_data[i];
        }
    }
    Array() : t_size(0), t_data(nullptr) {}
    Array(size_type size) : t_size(size), t_data(new T[size]) {}
    ~Array() { delete t_data;  t_data = nullptr; t_size = 0; }
    Array& operator=(const Array& rh) {
        if (&rh == this)return *this;
        delete t_data;
        t_size = rh.t_size;
        t_data = new T[rh.t_size];
        for (size_type i = 0; i < t_size; ++i) {
            t_data[i] = rh.t_data[i];
        }
        return *this;
    }
    T& operator[](size_type pos) { return t_data[pos]; }
    T operator[](size_type pos)const { return t_data[pos]; }
    size_type size() const { return t_size; }
    void clear() { delete t_data; t_data = nullptr; t_size = 0; }

    PtrIterator<T, size_type> begin() { return  { t_data, 0 }; }
    PtrIterator<T, size_type> end() { return { t_data, t_size }; }
  
    ConstPtrIterator<T, size_type> begin() const { return { t_data, 0 }; }
    ConstPtrIterator<T, size_type> end() const { return { t_data, t_size }; }
private:
    size_type t_size;
    T* t_data;
};