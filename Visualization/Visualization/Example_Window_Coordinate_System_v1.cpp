#include "Example_Window_Coordinate_System_v1.h"

void Example::Example_Window_Coordinate_System_v1::cb_btn_left(Fl_Widget* w, void* window)
{
	static_cast<Example::Example_Window_Coordinate_System_v1*>(window)->left();
}

void Example::Example_Window_Coordinate_System_v1::cb_btn_right(Fl_Widget* w, void* window)
{
	static_cast<Example::Example_Window_Coordinate_System_v1*>(window)->right();
}

void Example::Example_Window_Coordinate_System_v1::cb_btn_up(Fl_Widget* w, void* window)
{
	static_cast<Example::Example_Window_Coordinate_System_v1*>(window)->up();
}

void Example::Example_Window_Coordinate_System_v1::cb_btn_down(Fl_Widget* w, void* window)
{
	static_cast<Example::Example_Window_Coordinate_System_v1*>(window)->down();
}


void Example::Example_Window_Coordinate_System_v1::cb_slider_x(Fl_Widget *w, void *window)
{
	static_cast<Example::Example_Window_Coordinate_System_v1*>(window)->update_co_system_x_axis();
}
void Example::Example_Window_Coordinate_System_v1::cb_slider_y(Fl_Widget *w, void *window)
{
	static_cast<Example::Example_Window_Coordinate_System_v1*>(window)->update_co_system_y_axis();
}


void Example::Example_Window_Coordinate_System_v1::left()
{
	co_system.y_axis += 20;
	this->redraw();
}

void Example::Example_Window_Coordinate_System_v1::right()
{
	co_system.y_axis -= 20;
	this->redraw();
}

void Example::Example_Window_Coordinate_System_v1::up()
{
	co_system.x_axis += 20;
	this->redraw();
}

void Example::Example_Window_Coordinate_System_v1::down()
{
	co_system.x_axis -= 20;
	this->redraw();
}


void Example::Example_Window_Coordinate_System_v1::update_co_system_x_axis()
{
	std::cout << (double)slider_x.value() << std::endl;
	co_system.set_nX(-(double)slider_x.value());
	co_system.set_pX((double)slider_x.value());
	this->redraw();
}
void Example::Example_Window_Coordinate_System_v1::update_co_system_y_axis()
{
	std::cout << (double)slider_y.value() << std::endl;
	co_system.set_nY(-(double)slider_y.value());
	co_system.set_pY((double)slider_y.value());
	this->redraw();
}
