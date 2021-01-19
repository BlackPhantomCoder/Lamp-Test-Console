#pragma once
#include "Arduino.h"
#include "Types/Types.h"
#include "Data/CRGB.h"

class Adafruit_NeoPixel {
public:
	void clear() {
		for (size_t i = 0; i < 32; ++i) {
			t_data[i] = CRGB(0, 0, 0);
		}
	}
	void setPixelColor(::byte pos, const uint32_t& color) {
		t_data[pos] = CRGB(((color >> 16) & 0xff), ((color >> 8) & 0xff), (color & 0xff));
	}

	long getPixelColor(::byte pos) {
		return t_data[pos];
	}
private:
	CRGB t_data[32];
};