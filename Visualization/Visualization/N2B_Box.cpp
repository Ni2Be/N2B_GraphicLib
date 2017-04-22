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
	
	for (std::vector<NB::NB_Shape*>::iterator itr = owned_shapes.begin(); itr < owned_shapes.end(); itr++)
	{
		(*itr)->draw();
	}
	
	for (std::vector<NB::NB_Shape*>::iterator itr = shapes.begin(); itr < shapes.end(); itr++)
	{
		(*itr)->draw();
	}
	fl_pop_clip();
}

