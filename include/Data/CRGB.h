#pragma once
#include "Arduino.h"

//RGB container
struct CRGB {
    CRGB() = default;
    CRGB(byte r, byte g, byte b);

    ::byte red = 0;
    ::byte green = 0;
    ::byte blue = 0;
    operator uint32_t()const;
};