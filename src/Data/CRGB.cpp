#include "Data/CRGB.h"

CRGB::CRGB(): red(0), green(0), blue(0){

}

CRGB::CRGB(::byte r, ::byte g, ::byte b) : red(r), green(g), blue(b){

}

CRGB::operator uint32_t()const
{
	return ((uint32_t(red) << 16) | (uint32_t(green) << 8) | (uint32_t(blue)));
}