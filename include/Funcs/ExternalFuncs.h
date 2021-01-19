#pragma once
#include "Arduino.h"
#include "Types/Types.h"
#include "Types/ProgramTypes.h"
#include "Data/Array.h"
#include "Program.h"

class ExternalFuncs {
public:
	ExternalFuncs(ExternalFuncs&&) = default;
	ExternalFuncs(const ExternalFuncs&) = default;
	explicit ExternalFuncs(disp_up_fnc draw, pause_fnc pause, up_fnc update);
	void update();
	void draw();
	void pause(dbyte time);
private:
	up_fnc t_update;
	disp_up_fnc t_draw;
	pause_fnc t_pause;
};
