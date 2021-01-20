#pragma once
#include "Arduino.h"
#include "Types/Types.h"
#include "Data/CRGB.h"

//RGB strip emulation
class Adafruit_NeoPixel {
public:
	Adafruit_NeoPixel(Adafruit_NeoPixel&&) = default;
	Adafruit_NeoPixel(const Adafruit_NeoPixel&) = delete;
	Adafruit_NeoPixel() = default;
	
	Adafruit_NeoPixel& operator=(const Adafruit_NeoPixel&) = delete;

	//clear leds
	void clear();
	//set led color by pos
	void setPixelColor(::byte pos, const uint32_t& color);
	//get led color by pos
	long getPixelColor(::byte pos)const;
private:
	//leds array
	CRGB t_data[32];
};