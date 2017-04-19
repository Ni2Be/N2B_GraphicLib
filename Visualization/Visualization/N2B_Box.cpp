#include "N2B_Box.h"


NB::NB_Box::~NB_Box()
{
	for (auto i : this->shapes)
		delete i;
}

void NB::NB_Box::draw()
{
	for (std::vector<NB::NB_Shape*>::iterator itr = shapes.begin(); itr < shapes.end(); itr++)
	{
		(*itr)->draw();
	}
}