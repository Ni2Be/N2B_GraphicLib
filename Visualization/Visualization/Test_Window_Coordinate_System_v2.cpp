#include "Test_Window_Coordinate_System_v2.h"

void Test::Test_Window_Coordinate_System_v2::cb_btn_left(Fl_Widget* w, void* window)
{
	static_cast<Test::Test_Window_Coordinate_System_v2*>(window)->left();
}

void Test::Test_Window_Coordinate_System_v2::cb_btn_right(Fl_Widget* w, void* window)
{
	static_cast<Test::Test_Window_Coordinate_System_v2*>(window)->right();
}

void Test::Test_Window_Coordinate_System_v2::cb_btn_up(Fl_Widget* w, void* window)
{
	static_cast<Test::Test_Window_Coordinate_System_v2*>(window)->up();
}

void Test::Test_Window_Coordinate_System_v2::cb_btn_down(Fl_Widget* w, void* window)
{
	static_cast<Test::Test_Window_Coordinate_System_v2*>(window)->down();
}


void Test::Test_Window_Coordinate_System_v2::cb_slider_x(Fl_Widget *w, void *window)
{
	static_cast<Test::Test_Window_Coordinate_System_v2*>(window)->update_co_system_x_axis();
}
void Test::Test_Window_Coordinate_System_v2::cb_slider_y(Fl_Widget *w, void *window)
{
	static_cast<Test::Test_Window_Coordinate_System_v2*>(window)->update_co_system_y_axis();
}


void Test::Test_Window_Coordinate_System_v2::left()
{
	co_system.y_axis += 20;
	this->redraw();
}

void Test::Test_Window_Coordinate_System_v2::right()
{
	co_system.y_axis -= 20;
	this->redraw();
}

void Test::Test_Window_Coordinate_System_v2::up()
{
	co_system.x_axis += 20;
	this->redraw();
}

void Test::Test_Window_Coordinate_System_v2::down()
{
	co_system.x_axis -= 20;
	this->redraw();
}


void Test::Test_Window_Coordinate_System_v2::update_co_system_x_axis()
{
	std::cout << (double)slider_x->value() << std::endl;
	co_system.set_nX(-(double)slider_x->value());
	co_system.set_pX((double)slider_x->value());
	this->redraw();
}
void Test::Test_Window_Coordinate_System_v2::update_co_system_y_axis()
{
	std::cout << (double)slider_y->value() << std::endl;
	co_system.set_nY(-(double)slider_y->value());
	co_system.set_pY((double)slider_y->value());
	this->redraw();
}