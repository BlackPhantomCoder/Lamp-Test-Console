#include "Strip.h"

void Adafruit_NeoPixel::clear()
{
	for (size_t i = 0; i < 32; ++i) {
		t_data[i] = CRGB(0, 0, 0);
	}
}

void Adafruit_NeoPixel::setPixelColor(::byte pos, const uint32_t& color)
{
	t_data[pos] = CRGB(((color >> 16) & 0xff), ((color >> 8) & 0xff), (color & 0xff));
}

long Adafruit_NeoPixel::getPixelColor(::byte pos)const
{
	return t_data[pos];
}