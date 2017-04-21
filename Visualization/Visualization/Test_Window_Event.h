/**
*Test_Window_Event.h
*Purpose:
An Example that shows the main events that can be
catched by overwriting the FLTK handle() function.

int handle(int) is a FLTK function.
It is called every time the system recognizes an
event like a mouse move, or a pushed key.

@author Jordan
@version 1.0 04/21/17
*/
#pragma once
#include <FL/Fl_Button.H>
#include <FL/Fl_Slider.H>

#include "N2B_Window.h"
#include "N2B_Coordinate_System.h"

using namespace NB;
class Test_Window_Event : public NB_Window
{
public:
	Test_Window_Event()
		:NB_Window(400, 400, "Event Test")
	{
		this->end();
	}
private:
	//use something like
	//	std::cout << "key number: " << Fl::event_key() << std::endl;
	//in handle(int) to get the right numbers
	enum KEYS
	{
		UP = 65362, DOWN = 65364,
		LEFT = 65361, RIGHT = 65363
	};

	bool up;
	bool down;
	bool left;
	bool right;

	int handle(int e);
};
