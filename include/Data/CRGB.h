#pragma once
#include "Arduino.h"

class CRGB {
public:
    ::byte red, green, blue;
    CRGB();
    CRGB(::byte r, ::byte g, ::byte b);
    operator uint32_t()const;
};