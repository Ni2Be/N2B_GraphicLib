#include "N2B_Coordinate_System.h"

void N2B::N2B_Coordinate_System::set_visible(bool is_visible)
{
	vis = is_visible;
}

void N2B::N2B_Coordinate_System::draw()
{
	fl_color(FL_BLACK);
	fl_line(N2B_Box::x, N2B_Box::height / 2, N2B_Box::width, N2B_Box::height / 2);
	fl_line(N2B_Box::width / 2, N2B_Box::y, N2B_Box::width / 2, N2B_Box::height);

	N2B_Box::draw();
}

void N2B::N2B_Function_Graph::draw()
{
	fl_color(FL_BLACK);
	for (int i = 1; i < root->width; i++)
	{
		fl_line(i - 1, 
			root->height / 2 - intfunc(i - 1 - (root->width / 2)), i,
			root->height / 2 - intfunc(i - (root->width / 2)));
	}
}