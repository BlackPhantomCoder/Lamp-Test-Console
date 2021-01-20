#pragma once
#include "Arduino.h"
#include "Types/Types.h"
#include "Types/ProgramTypes.h"
#include "Data/Array.h"
#include "Program.h"

//External Funcs container
class ExternalFuncs {
public:
	ExternalFuncs(ExternalFuncs&&) = default;
	ExternalFuncs(const ExternalFuncs&) = default;

	explicit ExternalFuncs(disp_up_fnc draw, pause_fnc pause, up_fnc update);

	//update fnc
	void update();
	//draw fnc
	void draw();
	//pause fnc
	void pause(dbyte time);
private:
	disp_up_fnc t_draw;
	pause_fnc t_pause;
	up_fnc t_update;
};
