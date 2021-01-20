#pragma once
#include "Arduino.h"
#include "Data/CRGB.h"
#include "Types/Types.h"
#include "Strip.h"

//32 RGB ardess strip controller
//Adress: 0-7 -> 0-7 leds
//Adress: 8-15 -> 15-8 leds
//Adress: 16-23 -> 16-23 leds
//Adress: 24-31 -> 31-24 leds
//all leds val updates by brightness val
class LedsController32 {
public:
	//set modes
	enum leds_color {
		red,
		green,
		blue
	};
public:
	LedsController32(const LedsController32&) = default;
	LedsController32(Adafruit_NeoPixel& strip, ::byte brightness);
	~LedsController32() = default;

	LedsController32& operator=(const LedsController32&) = default;
	

	//swap 2 leds
	void swap(::byte pos_i, ::byte pos_j);
	//copy led i to led j
	void copy(::byte pos_i, ::byte pos_j);
	//set led by aress
	void set(::byte pos, CRGB rgb);
	//set led by aress with mode
	void set(::byte pos, ::byte val, leds_color c);
	//get led by aress
	CRGB get(::byte pos);
	//clear all leds to (0,0,0)
	void clear();
	//return strip brightness
	::byte get_brightness() const;
	//set strip brightness (all leds update) 
	void set_brightness(::byte val);
private:
	//update val
	::byte t_to_brightness(::byte val);
	//get color from strip
	CRGB t_get_color(::byte i);
	//pos to adress
	::byte t_adress(::byte pos);
	//add update fnc
	::byte t_get_new_a(::byte new_brightness);
private:
	//strip
	Adafruit_NeoPixel& t_strip;
	//brightness val
	::byte t_brightness;
	//add update val
	::byte t_a;
};