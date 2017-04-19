#include "N2B_Window.h"

NB::NB_Window::~NB_Window()
{
}

void NB::NB_Window::attatch(NB::NB_Box& box)
{
	this->boxes.push_back(&box);
}

void NB::NB_Window::draw()
{
	Fl_Window::draw();
	for (std::vector<NB::NB_Box*>::iterator itr = boxes.begin(); itr < boxes.end(); itr++)
	{
		(*itr)->draw();
	}

}