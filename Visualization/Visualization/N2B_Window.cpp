#include "N2B_Window.h"

N2B::N2B_Window::~N2B_Window()
{
}

void N2B::N2B_Window::attatch(N2B::N2B_Box& box)
{
	this->boxes.push_back(&box);
}

void N2B::N2B_Window::draw()
{
	Fl_Window::draw();
	for (std::vector<N2B::N2B_Box*>::iterator itr = boxes.begin(); itr < boxes.end(); itr++)
	{
		(*itr)->draw();
	}

}