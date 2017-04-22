#include "N2B_Window.h"

void NB::NB_Window::attach(NB::NB_Box& box)
{
	this->boxes.push_back(&box);
	box.root = this;
}

void NB::NB_Window::draw()
{
	//draws widgets and background
	Fl_Window::draw();
	
	//draws boxes
	for (std::vector<NB::NB_Box*>::iterator itr = boxes.begin(); itr < boxes.end(); itr++)
	{
		(*itr)->draw();
	}

	//draws widgets again
	for (int i = 0; i < this->children(); i++)
		this->child(i)->draw();
}
