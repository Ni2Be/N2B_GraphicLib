/**
*Example_Window_Event.h
*Purpose:
An Example that shows the main events that can be
catched by overwriting the FLTK handle() function.

since v. 1.1
Also a litte example of a game loop

int handle(int) is a FLTK function.
It is called every time the system recognizes an
event like a mouse move, or a pushed key.

@author Jordan
@version 1.1 04/22/17
*/
#pragma once
#include <FL/Fl_Button.H>
#include <FL/Fl_Slider.H>

#include <chrono>

#include "N2B_Window.h"
#include "N2B_Coordinate_System.h"

namespace Example {
	using namespace NB;
	class Example_Window_Event : public NB_Window
	{
	public:
		Example_Window_Event()
			:NB_Window(400, 400, "Event"),
			b(0, 0, 400, 400),
			square(NB_Point(180, 180), 20, 20, NB_BLUE)
		{
			b.attach(square);
			this->attach(b);
			this->end();

			//tell the System to call back after starting NB_run()
			Fl::add_timeout(0.01, cb_timer, (void*)this);
		}
	private:
		NB_Box b;
		NB_RectF square;
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

		static void cb_timer(void *window);
		void game_loop();

		void moving();

		int handle(int e);
	};
}
