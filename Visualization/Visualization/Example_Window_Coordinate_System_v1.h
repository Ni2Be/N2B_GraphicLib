/**
*Example_Window_Coordinate_System_v1.h
*Purpose:
A Window that shows an example of how to use N2B_Coordinate_System.
It also shows two different ways of resource handling:
Version 1 with local saved Fl_Widgets,
Version 2 with references to the Widgets.

@author Jordan
@version 1.0 04/21/17
*/

#pragma once
#include <FL/Fl_Button.H>
#include <FL/Fl_Slider.H>

#include "N2B_Window.h"
#include "N2B_Coordinate_System.h"

namespace Example
{
	/**
	The function that will be displayed in the
	NB_Function_Graph "graph".
	*/
	static double showed_function_v1(double x)
	{
		return std::sin(x) + std::pow(3, x);
	};

	using namespace NB;
	
	class Example_Window_Coordinate_System_v1 : public NB_Window
	{
	public:
		//The Buttons are constructed in the window
		Example_Window_Coordinate_System_v1()
			:NB_Window(400, 400, "Coordinate v1"),
			btn_left(40, 30, 20, 20, "<"),
			btn_right(80, 30, 20, 20, ">"),
			btn_up(60, 10, 20, 20, "^"),
			btn_down(60, 50, 20, 20, "v"),
			slider_x(20, 70, 100, 20),
			slider_y(20, 95, 100, 20),
			co_system(100, 100, 200, 200, -5, 5, -5, 5, true),
			graph(showed_function_v1)
		{
			this->end();//ends adding widgets to this window

			//set up the sliders
			slider_x.type(1);
			slider_x.bounds(1, 100);
			slider_x.value(5);
			slider_x.callback(cb_slider_x, this);

			slider_y.type(1);
			slider_y.bounds(1, 100);
			slider_y.value(5);
			slider_y.callback(cb_slider_y, this);


			//set up the buttons
			btn_left.callback(cb_btn_left, this);
			btn_right.callback(cb_btn_right, this);
			btn_up.callback(cb_btn_up, this);
			btn_down.callback(cb_btn_down, this);

			//set up the coordinate system
			co_system.attach(graph);
			this->attach(co_system);
		}

	private:
		NB_Coordinate_System co_system;
		NB_Function_Graph graph;

		Fl_Button btn_left;
		Fl_Button btn_right;
		Fl_Button btn_up;
		Fl_Button btn_down;

		Fl_Slider slider_x;
		Fl_Slider slider_y;


		//Button callbacks
		static void cb_btn_left(Fl_Widget* w, void* window);
		static void cb_btn_right(Fl_Widget* w, void* window);
		static void cb_btn_up(Fl_Widget* w, void* window);
		static void cb_btn_down(Fl_Widget* w, void* window);

		//Button actions
		void left();
		void right();
		void up();
		void down();

		//Slider callbacks
		static void cb_slider_x(Fl_Widget *w, void *window);
		static void cb_slider_y(Fl_Widget *w, void *window);

		//Slider actions
		void update_co_system_x_axis();
		void update_co_system_y_axis();
	};
}
