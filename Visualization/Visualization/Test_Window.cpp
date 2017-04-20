#include "Test_Window.h"

void Test_Window::cb_left(Fl_Widget* w, void* window)
{
	static_cast<Test_Window*>(window)->left();
}

void Test_Window::cb_right(Fl_Widget* w, void* window)
{
	static_cast<Test_Window*>(window)->right();
}

void Test_Window::cb_up(Fl_Widget* w, void* window)
{
	static_cast<Test_Window*>(window)->up();
}

void Test_Window::cb_down(Fl_Widget* w, void* window)
{
	static_cast<Test_Window*>(window)->down();
}


void Test_Window::cb_slider_x(Fl_Widget *w, void *window)
{
	static_cast<Test_Window*>(window)->slider_x_input();
}
void Test_Window::cb_slider_y(Fl_Widget *w, void *window)
{
	static_cast<Test_Window*>(window)->slider_y_input();
}


void Test_Window::left()
{
	co.y_axis -= 20;
	this->redraw();
}

void Test_Window::right()
{
	co.y_axis += 20;
	this->redraw();
}

void Test_Window::up()
{
	co.x_axis -= 20;
	this->redraw();
}

void Test_Window::down()
{
	co.x_axis += 20;
	this->redraw();
}


void Test_Window::slider_x_input()
{
	std::cout << (double)slider_x.value() << std::endl;
	co.set_nX(-(double)slider_x.value());
	co.set_pX((double)slider_x.value());
	this->redraw();
}
void Test_Window::slider_y_input()
{
	std::cout << (double)slider_y.value() << std::endl;
	co.set_nY(-(double)slider_y.value());
	co.set_pY((double)slider_y.value());
	this->redraw();
}
