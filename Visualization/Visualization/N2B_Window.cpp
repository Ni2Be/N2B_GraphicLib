#include "N2B_Window.h"

void NB::NB_Window::attach(NB::NB_Box& box)
{
	this->boxes.push_back(&box);
	box.root = this;
}

void NB::NB_Window::draw()
{
	Fl_Window::draw();
	for (std::vector<NB::NB_Box*>::iterator itr = boxes.begin(); itr < boxes.end(); itr++)
	{
		(*itr)->draw();
	}
}
