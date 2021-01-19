#pragma once
#include "Arduino.h"
#include "Array.h"

using CharArray = Array<char, ::byte>;

class CharArrayView
{
public:
    CharArrayView(CharArray& arr) : t_data(&arr), t_left(0), t_right(0) {}
    char& operator[](::byte i) { return (*t_data)[i + t_left]; }
    char operator[](::byte i)const { return (*t_data)[i + t_left]; }
    void remove_beg(::byte val) { t_left += val; }
    void remove_end(::byte val) { t_right += val; }
    CharArrayView& operator=(const CharArrayView& rh) {
        t_data = rh.t_data;
        t_left = rh.t_left;
        t_right = rh.t_right;
        return *this;
    }

    ::byte size()const { return (*t_data).size() - t_left - t_right; }
private:
    CharArray* t_data;
    ::byte t_left;
    ::byte t_right;
};