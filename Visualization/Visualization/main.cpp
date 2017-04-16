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
		N2B_Box b1(0, 200, 0, 200);
		win1.attatch(b1);
		
		b1.attach(N2B_Line(N2B_Point(20, 20), N2B_Point(220, 120)));
		b1.attach(N2B_Mark(N2B_Point(20, 20), "x"));

		win1.resizable(win1);
		win1.show();

		return N2B_run();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
}
