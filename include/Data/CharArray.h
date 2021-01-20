#pragma once
#include "Arduino.h"
#include "Array.h"

//Array of char
using CharArray = Array<char, ::byte>;

//read-only view
class CharArrayConstView
{
public:
    CharArrayConstView(const CharArrayConstView&) = default;

    CharArrayConstView(const CharArray& arr);
    ~CharArrayConstView() = default;

    CharArrayConstView& operator=(const CharArrayConstView& rh) = default;

    //read element from view
    char operator[](::byte i)const;
    //remove element from begin of view
    void remove_beg(::byte val);
    //remove element from end of view
    void remove_end(::byte val);
    //size of available elements
    ::byte size()const;
private:
    //data array
    const CharArray* t_data;
    //left offset
    ::byte t_left;
    //right offset
    ::byte t_right;
};