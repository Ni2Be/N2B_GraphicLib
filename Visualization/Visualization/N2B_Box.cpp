#include "N2B_Box.h"


N2B::N2B_Box::~N2B_Box()
{
	for (auto i : this->shapes)
		delete i;
}

void N2B::N2B_Box::draw()
{
	for (std::vector<N2B::N2B_Shape*>::iterator itr = shapes.begin(); itr < shapes.end(); itr++)
	{
		(*itr)->draw();
	}
}