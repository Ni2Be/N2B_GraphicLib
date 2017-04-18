#include "N2B_Coordinate_System.h"

void N2B::N2B_Coordinate_System::set_visible(bool is_visible)
{
	is_vis = is_visible;
}

void N2B::N2B_Coordinate_System::draw()
{
	fl_color(FL_BLACK);
	fl_line(N2B_Box::x, N2B_Box::height / 2, N2B_Box::width, N2B_Box::height / 2);
	fl_line(N2B_Box::width / 2, N2B_Box::y, N2B_Box::width / 2, N2B_Box::height);

	if (is_vis)
	{
		//axis
		int x_pixel = width / (p_X - n_X);
		int pix_to_null = (width / 2) % x_pixel;
		for (int i = pix_to_null; i < width; i += x_pixel)
		{
			fl_line(i, 5 + height / 2, i, -5 + height / 2);
		}

		int y_pixel = height / (p_Y - n_Y);
		pix_to_null = (height / 2) % y_pixel;
		for (int i = pix_to_null; i < height; i += y_pixel)
		{
			fl_line(5 + width / 2, i, -5 + width / 2, i);
		}
	}
	//functions
	for (std::vector<N2B::N2B_Function_Graph*>::iterator itr = functions.begin(); itr < functions.end(); itr++)
	{
		(*itr)->draw();
	}

	//shapes
	N2B_Box::draw();
}

void N2B::N2B_Function_Graph::draw()
{
	double x_factor = (root->p_X - root->n_X) / root->width;
	double y_factor = (root->p_Y - root->n_Y) / root->height;
	fl_color(FL_BLACK);

	//3 should be a variable like "resulution" of root
	int res = 3;

	int pix_to_null = (root->width / 2) % res;
	for (int i = pix_to_null - (root->width / 2); i < (root->width / 2) + res; i += res)
	{
		double real_x_prev = (i - res) * x_factor; //like f(real_x)=real_x^2   
		double real_y_prev = func(real_x_prev);//like f(x)=real_y
		double screen_y_prev = root->height / 2 - real_y_prev / y_factor;//real y position on screen

		double real_x = i * x_factor;
		double real_y = func(real_x);
		double screen_y = root->height / 2 - real_y / y_factor;

		//draw line
		fl_line((root->width / 2) + i - res,
			screen_y_prev,
			(root->width / 2) + i,
			screen_y);
	}
}