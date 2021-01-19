#include <iostream>
#include <fstream>

#include "Arduino.h"
#include "Types/Types.h"
#include "LedsController.h"
#include "LampController.h"
#include "Strip.h"
#include "Funcs/ExternalFuncs.h"

using namespace std;
Adafruit_NeoPixel strip;
LedsController32 core(strip,255);

void draw() {
	for (::byte j = 0; j < 4; ++j)
	{
		for (::byte i = 0; i < 8; ++i) {
			cout
				<< ((core.get(j * 8 + i).red) * 10) / (2550 / core.get_brightness())
				<< " " 
				<< ((core.get(j * 8 + i).green) * 10) / (2550 / core.get_brightness())
				<< " " 
				<< ((core.get(j * 8 + i).blue) * 10) / (2550 / core.get_brightness())
				<< "|";
		}
		cout << endl;
	}
}

void update() {
	cout << "update" << endl;
}

void pause(dbyte time) {
	cout << "pause " << time << endl;
}

int main() {
	String filename = "testLAMP/RB2.p";

	ifstream program(filename, ios::binary);
	ReadFile f(program, filename);
	LampController controller(f, core, ExternalFuncs(draw, pause, update));
 	while (controller.update()) {}
}