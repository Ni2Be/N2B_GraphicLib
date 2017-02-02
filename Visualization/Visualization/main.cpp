#include <iostream>
#include <FL/Fl.H>

#include "N2B_Graphics.h"
#include "N2B_Coordinate_System.h"
#include "N2B_Container.h"
#include "N2B_MainWin.h"

using namespace N2B;
int main() 
{
	try 
	{
		N2B_Window win1(200, 200, "win1");

		N2B_Container *box1 = new N2B_Container(0, 0, 200, 200);
		box1->add_shape(N2B_Line(N2B_Point(10, 10), N2B_Point(100,  100)));

		win1.add_Container(*box1);

		win1.resizable(win1);
		win1.show();
		return N2B_run();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
}
