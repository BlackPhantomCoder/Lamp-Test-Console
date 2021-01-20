#include "LedsController.h"

LedsController32::LedsController32(Adafruit_NeoPixel& strip, ::byte brightness):
	t_strip(strip),
	t_brightness(brightness),
	t_a(t_get_new_a(brightness))
{}

void LedsController32::swap(::byte pos_i, ::byte pos_j)
{
	auto val_i = t_strip.getPixelColor(t_adress(pos_i));
	t_strip.setPixelColor(t_adress(pos_i), t_strip.getPixelColor(t_adress(pos_j)));
	t_strip.setPixelColor(t_adress(pos_j), val_i);
}

void LedsController32::copy(::byte pos_i, ::byte pos_j)
{
	t_strip.setPixelColor(t_adress(pos_i), t_strip.getPixelColor(t_adress(pos_j)));
}

void LedsController32::set(::byte pos, CRGB rgb)
{
	rgb.blue = t_to_brightness(rgb.blue);
	rgb.green = t_to_brightness(rgb.green);
	rgb.red = t_to_brightness(rgb.red);
	t_strip.setPixelColor(t_adress(pos), rgb);
}

void LedsController32::set(::byte pos, ::byte val, leds_color c)
{
	val = t_to_brightness(val);
	uint32_t clr = t_strip.getPixelColor(t_adress(pos));
	switch (c)
	{
	case leds_color::red:
		clr = (uint32_t(val & 0xff) << 16) | (((clr >> 8) & 0xff) << 8) | (clr & 0xff);
		break;
	case leds_color::green:
		clr = (uint32_t(val & 0xff) << 8) | (((clr >> 16) & 0xff) << 16) | (clr & 0xff);
		break;
	case leds_color::blue:
		clr = (val & 0xff) | (((clr >> 16) & 0xff) << 16) | ((((clr >> 8) & 0xff) << 8));
		break;
	}
	t_strip.setPixelColor(t_adress(pos), clr);
}

CRGB LedsController32::get(::byte pos)
{
	return t_get_color(t_adress(pos));
}

void LedsController32::clear()
{
	t_strip.clear();
}

::byte LedsController32::get_brightness() const
{
	return t_brightness;
}

void LedsController32::set_brightness(::byte val)
{
	t_a = t_get_new_a(val);
	for (::byte i = 0; i < 32; ++i) {
		auto color = t_get_color(t_adress(i));
		set(i, CRGB(t_to_brightness((color >> 16) & 0xff), t_to_brightness((color >> 8) & 0xff), t_to_brightness(color & 0xff)));
	}
	t_brightness = val;
}

::byte LedsController32::t_to_brightness(::byte val)
{
	return dbyte(val * 10) / t_a;
}

CRGB LedsController32::t_get_color(::byte i)
{
	uint32_t color = t_strip.getPixelColor(i);
	return CRGB(((color >> 16) & 0xff) * t_a / 10, ((color >> 8) & 0xff) * t_a / 10, (color & 0xff) * t_a / 10);
}

::byte LedsController32::t_adress(::byte pos)
{
	if (pos < 8)return pos;
	if (pos >= 8 && pos < 16) return 23 - pos;
	if (pos >= 16 && pos < 24)return pos;
	if (pos >= 24 && pos < 32) return 55 - pos;
	return pos;
}

::byte LedsController32::t_get_new_a(::byte new_brightness)
{
	return (2550 / dbyte(new_brightness));
}
