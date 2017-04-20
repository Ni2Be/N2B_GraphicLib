#pragma once
#include <FL/Fl_Button.H>
#include <FL/Fl_Slider.H>

#include "N2B_Window.h"
#include "N2B_Coordinate_System.h"

static double sin_function(double x)
{
	return std::sin(x) + std::pow(3, x);
};

using namespace NB;
class Test_Window : public NB_Window
{
public:
	Test_Window()
		:NB_Window(400, 400, "Test Window"),
		b_left(40, 30, 20, 20, "<"),
		b_right(80, 30, 20, 20, ">"),
		b_up(60, 10, 20, 20, "^"),
		b_down(60, 50, 20, 20, "v"),
		slider_x(20, 70, 100, 20),
		slider_y(20, 95, 100, 20),
		co(0, 0, 400, 400, -5, 5, -5, 5, true),
		sinus(sin_function)
	{
		slider_x.type(1);
		slider_x.bounds(1, 100);
		slider_x.value(5);
		slider_x.callback(cb_slider_x, this);
		
		slider_y.type(1);
		slider_y.bounds(1, 100);
		slider_y.value(5);
		slider_y.callback(cb_slider_y, this);

		b_left.callback(cb_left, this);
		b_right.callback(cb_right, this);
		b_up.callback(cb_up, this);
		b_down.callback(cb_down, this);

		co.attach(sinus);
		this->attach(co);
	}

private:
	NB_Coordinate_System co;
	NB_Function_Graph sinus;


	Fl_Button b_left;
	Fl_Button b_right;
	Fl_Button b_up;
	Fl_Button b_down;

	Fl_Slider slider_x;
	Fl_Slider slider_y;


	static void cb_left(Fl_Widget* w, void* window);
	static void cb_right(Fl_Widget* w, void* window);
	static void cb_up(Fl_Widget* w, void* window);
	static void cb_down(Fl_Widget* w, void* window);

	static void cb_slider_x(Fl_Widget *w, void *window);
	static void cb_slider_y(Fl_Widget *w, void *window);


	void left();
	void right();
	void up();
	void down();

	void slider_x_input();
	void slider_y_input();
};
