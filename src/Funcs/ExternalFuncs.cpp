#include "Funcs/ExternalFuncs.h"

ExternalFuncs::ExternalFuncs(disp_up_fnc draw, pause_fnc pause, up_fnc update) :
    t_draw(draw),
    t_pause(pause),
    t_update(update)
{
}

void ExternalFuncs::update()
{
    t_update();
}

void ExternalFuncs::draw()
{
    t_draw();
}

void ExternalFuncs::pause(dbyte time)
{
    t_pause(time);
}