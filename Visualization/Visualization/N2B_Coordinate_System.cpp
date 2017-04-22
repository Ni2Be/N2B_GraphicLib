#include "N2B_Coordinate_System.h"

void NB::NB_Coordinate_System::set_visible(bool is_visible)
{
	is_vis = is_visible;
}

void NB::NB_Coordinate_System::draw()
{
	Fl_Color old_c = fl_color();
	fl_color(color);

	fl_clip(this->x, this->y, this->width, this->height);
	//x-axis
	fl_line(neg_x + x, x_axis + y, width + x, x_axis + y);
	//y-axis
	fl_line(y_axis + x, y, y_axis + x, height + y);

	if (is_vis)
	{
		//units
		int unit_pix = 5;
		int x_pixel = width / (pos_x - neg_x);
		int pix_to_null = (y_axis) % x_pixel;
		for (int i = pix_to_null + x; i < width + x; i += x_pixel)
		{
			fl_line(i, unit_pix + x_axis + y, i, -unit_pix + x_axis + y);
		}

		int y_pixel = height / (pos_y - neg_y);
		pix_to_null = (x_axis) % y_pixel;
		for (int i = pix_to_null + y; i < height + y; i += y_pixel)
		{
			fl_line(unit_pix + y_axis + x, i, -unit_pix + y_axis + x, i);
		}
	}
	//functions
	for (std::vector<NB::NB_Function_Graph*>::iterator itr = graphs.begin(); itr < graphs.end(); itr++)
	{
		(*itr)->draw();
	}
	fl_pop_clip();

	fl_color(old_c);

	//shapes
	NB_Box::draw();
}

void NB::NB_Function_Graph::draw()
{
	double x_factor = (root->pos_x - root->neg_x) / root->width;
	double y_factor = (root->pos_y - root->neg_y) / root->height;

	Fl_Color old_c = fl_color();
	fl_color(color);
	//3 should be a variable like "resulution", of root
	int res = 3;
	int pix_to_null = (root->y_axis) % res;
	for (int i = pix_to_null - (root->y_axis); i < (root->width) + res; i += res)
	{
		double real_x_prev = (i - res) * x_factor;    
		double real_y_prev = func(real_x_prev);
		double screen_y_prev = root->x_axis - real_y_prev / y_factor;
		
		double real_x = i * x_factor;
		double real_y = func(real_x);
		double screen_y = root->x_axis - real_y / y_factor;

		//draw line
		fl_line((root->y_axis) + i - res + root->x,
			screen_y_prev + root->y,
			(root->y_axis) + i + root->x,
			screen_y + root->y);
	}
	fl_color(old_c);
}

void NB::NB_Coordinate_System::set_nX(double x)
{
	if (x >= 0)
		throw std::runtime_error("\nclass NB_Coordinate_System\set_nX():\nWrong nx\n");
	this->neg_x = x;
}

void NB::NB_Coordinate_System::set_nY(double y)
{
	if (y >= 0)
		throw std::runtime_error("\nclass NB_Coordinate_System\set_nX():\nWrong ny\n");
	this->neg_y = y;
}

void NB::NB_Coordinate_System::set_pX(double x) 
{
	if (x <= 0)
		throw std::runtime_error("\nclass NB_Coordinate_System\set_nX():\nWrong px\n");
	this->pos_x = x;
}

void NB::NB_Coordinate_System::set_pY(double y)
{
	if (y <= 0)
		throw std::runtime_error("\nclass NB_Coordinate_System\set_nX():\nWrong py\n");
	this->pos_y = y;
}
