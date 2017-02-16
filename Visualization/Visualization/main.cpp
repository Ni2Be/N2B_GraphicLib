#include <iostream>
#include <FL/Fl.H>

#include "N2B_Window.h"
#include "N2B_Box.h"
#include "N2B_Graphics.h"

using namespace N2B;
int main() 
{
	try 
	{
		N2B_Window win1(200, 200, "win1");

		win1.attatch(N2B_Box(0,0,0,0));

		win1.resizable(win1);
		win1.show();
		return N2B_run();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
}
