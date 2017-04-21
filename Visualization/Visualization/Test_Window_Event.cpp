#include "Test_Window_Event.h"

int Test_Window_Event::handle(int e) 
{
	int ret = Fl_Window::handle(e);
	switch (e)
	{
	case FL_MOVE:
		//whould be "couted" to often
		//std::cout << "moved!";
		break;
	case FL_PUSH:
		std::cout << "pushed:" << Fl::event_button() << std::endl;
		std::cout << "root: " << Fl::event_x_root() << " | " << Fl::event_y_root() << std::endl;
		std::cout << "no r: " << Fl::event_x() << " | " << Fl::event_y() << std::endl;
		break;
	case FL_DRAG:
		std::cout << "drag:\n";
		std::cout << "root: " << Fl::event_x_root() << " | " << Fl::event_y_root() << std::endl;
		std::cout << "no r: " << Fl::event_x() << " | " << Fl::event_y() << std::endl;
		break;
	case FL_RELEASE:
		std::cout << "release:\n";
		std::cout << "root: " << Fl::event_x_root() << " | " << Fl::event_y_root() << std::endl;
		std::cout << "no r: " << Fl::event_x() << " | " << Fl::event_y() << std::endl;
		break;
	case FL_MOUSEWHEEL:
		std::cout << "wheel:\n";
		std::cout << "x | y: " << Fl::event_dx() << " | " << Fl::event_dy() << std::endl;
		break;
	case FL_SHORTCUT:
		//whould be "couted" to often
		//std::cout << "Short cut: " << Fl::event_key() << std::endl;
		break;
	case FL_ENTER:
		std::cout << "entered!\n";
		break;
	case FL_LEAVE:
		std::cout << "leaved!\n";
		break;
	case FL_HIDE:
		std::cout << "hide!\n";
	}

	//Excample of simple arrow controlls
	if (e == FL_KEYDOWN)
	{
		int pressed = Fl::event_key();
		switch (pressed)
		{
		case UP:
			if (!up)
			{
				up = true;
				std::cout << "up: " << Fl::event_key() << std::endl;
			}
			break;
		case DOWN:
			if (!down)
			{
				down = true;
				std::cout << "down: " << Fl::event_key() << std::endl;
			}
			break;
		case LEFT:
			if (!left)
			{
				left = true;
				std::cout << "left: " << Fl::event_key() << std::endl;
			}
			break;
		case RIGHT:
			if (!right)
			{
				right = true;
				std::cout << "right: " << Fl::event_key() << std::endl;
			}
			break;
		}
	}

	if (e == FL_KEYUP)
	{
		int pressed = Fl::event_key();
		switch (pressed)
		{
		case UP:
			up = false;
			std::cout << "up: " << Fl::event_key() << std::endl;
			break;
		case DOWN:
			down = false;
			std::cout << "down: " << Fl::event_key() << std::endl;
			break;
		case LEFT:
			left = false;
			std::cout << "left: " << Fl::event_key() << std::endl;
			break;
		case RIGHT:
			right = false;
			std::cout << "right: " << Fl::event_key() << std::endl;
			break;
		}
	}

	return(ret);
}
