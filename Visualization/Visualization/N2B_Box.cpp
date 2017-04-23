#include "N2B_Box.h"


NB::NB_Box::~NB_Box()
{
	for (auto i : this->owned_shapes)
		delete i;
}

void NB::NB_Box::draw()
{
	fl_clip(this->x, this->y, this->width, this->height);
	for (auto b : boxes)
	{
		b->draw();
	}
	for (auto itr : owned_shapes)
	{
		itr->draw();
	}

	for (auto itr : shapes)
	{
		itr->draw();
	}
	/*
	for (auto itr = owned_shapes.begin(); itr < owned_shapes.end(); itr++)
	{
		(*itr)->draw();
	}
	
	for (auto itr = shapes.begin(); itr < shapes.end(); itr++)
	{
		(*itr)->draw();
	}
	*/
	fl_pop_clip();
}

