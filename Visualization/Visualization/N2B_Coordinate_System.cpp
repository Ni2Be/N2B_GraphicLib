#include "N2B_Coordinate_System.h"

void NB::NB_Coordinate_System::set_visible(bool is_visible)
{
	is_vis = is_visible;
}

void NB::NB_Coordinate_System::draw()
{
	Fl_Color old_c = fl_color();
	fl_color(color);

	fl_line(n_X, x_axis, NB_Box::width, x_axis);
	fl_line(y_axis, NB_Box::y, y_axis, NB_Box::height);

	if (is_vis)
	{
		//units
		int unit_pix = 5;
		int x_pixel = width / (p_X - n_X);
		int pix_to_null = (y_axis) % x_pixel;
		for (int i = pix_to_null; i < width; i += x_pixel)
		{
			fl_line(i, unit_pix + x_axis, i, -unit_pix + x_axis);
		}

		int y_pixel = height / (p_Y - n_Y);
		pix_to_null = (x_axis) % y_pixel;
		for (int i = pix_to_null; i < height; i += y_pixel)
		{
			fl_line(unit_pix + y_axis, i, -unit_pix + y_axis, i);
		}
	}
	//functions
	for (std::vector<NB::NB_Function_Graph*>::iterator itr = functions.begin(); itr < functions.end(); itr++)
	{
		(*itr)->draw();
	}

	fl_color(old_c);
	//shapes
	NB_Box::draw();
}

void NB::NB_Function_Graph::draw()
{
	double x_factor = (root->p_X - root->n_X) / root->width;
	double y_factor = (root->p_Y - root->n_Y) / root->height;

	Fl_Color old_c = fl_color();
	fl_color(color);

	//3 should be a variable like "resulution" of root
	int res = 3;
	int pix_to_null = (root->y_axis) % res;
	for (int i = pix_to_null - (root->y_axis); i < (root->y_axis) + res; i += res)
	{
		double real_x_prev = (i - res) * x_factor; //like f(real_x)=real_x^2   
		double real_y_prev = func(real_x_prev);//like f(x)=real_y
		double screen_y_prev = root->x_axis - real_y_prev / y_factor;//real y position on screen

		double real_x = i * x_factor;
		double real_y = func(real_x);
		double screen_y = root->x_axis - real_y / y_factor;

		//draw line
		fl_line((root->y_axis) + i - res,
			screen_y_prev,
			(root->y_axis) + i,
			screen_y);
	}
	fl_color(old_c);
}

void NB::NB_Coordinate_System::set_nX(double x)
{
	if (x >= 0)
		throw std::runtime_error("\nclass NB_Coordinate_System\set_nX():\nWrong nx\n");
	this->n_X = x;
}

void NB::NB_Coordinate_System::set_nY(double y)
{
	if (y >= 0)
		throw std::runtime_error("\nclass NB_Coordinate_System\set_nX():\nWrong ny\n");
	this->n_Y = y;
}

void NB::NB_Coordinate_System::set_pX(double x) 
{
	if (x <= 0)
		throw std::runtime_error("\nclass NB_Coordinate_System\set_nX():\nWrong px\n");
	this->p_X = x;
}

void NB::NB_Coordinate_System::set_pY(double y)
{
	if (y <= 0)
		throw std::runtime_error("\nclass NB_Coordinate_System\set_nX():\nWrong py\n");
	this->p_Y = y;
}
