#include "N2B_Box.h"


NB::NB_Box::~NB_Box()
{
	/*not used
	for (auto i : this->owned_shapes)
		delete i;
	*/
}

void NB::NB_Box::draw()
{
	for (auto b : boxes)
	{
		b->draw();
	}
	/*not used
	for (std::vector<NB::NB_Shape*>::iterator itr = owned_shapes.begin(); itr < owned_shapes.end(); itr++)
	{
		(*itr)->draw();
	}
	*/
	for (std::vector<NB::NB_Shape*>::iterator itr = shapes.begin(); itr < shapes.end(); itr++)
	{
		(*itr)->draw();
	}
}

