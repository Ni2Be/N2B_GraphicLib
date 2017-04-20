#include <iostream>
#include <math.h>
#include <random>

#include "N2B_Window.h"
#include "N2B_Box.h"
#include "N2B_Graphics.h"
#include "N2B_Coordinate_System.h"

#include "Test_Window.h"

using namespace NB;
int main()
{
	try
	{
		Test_Window test1;
		test1.show();
		/*
		NB_Window win1(400, 400, "win1");
		NB_Box b1(0, 0, 200, 200);
		
		//Line
		NB_Line line1(NB_Point(20, 20), NB_Point(220, 120));
		b1.attach(line1);

		//Mark
		NB_Mark mark1(NB_Point(20, 20), "x", NB_BLUE);
		b1.attach(mark1);
		
		//Polyline
		std::vector<NB_Point> pV;
		pV.push_back(NB_Point(20, 100));
		pV.push_back(NB_Point(50, 300));
		pV.push_back(NB_Point(203, 400));
		pV.push_back(NB_Point(2, 50));
		NB_Polyline p(pV);
		b1.attach(p);

		//Rect / F
		NB_Rect r(NB_Point(50, 50), 40, 50, NB_GRAY);
		NB_RectF rf(NB_Point(90, 90), 40, 50, NB_BLUE);
		b1.attach(r);
		b1.attach(rf);

		win1.attach(b1);

		//Coordinate System
		NB_Coordinate_System co(0, 0, 400, 400, -3, 5, -2, 5, true, NB_RED);
		auto sin_function = [](double x) -> double
		{
			return std::sin(x);
		};
		NB_Function_Graph sinus(sin_function, NB_GREEN);
		co.attach(sinus);

		auto exp_function = [](double x) -> double
		{
			return std::pow(x, 2) + 0.6;
		};
		NB_Function_Graph e(exp_function);
		//co.detach(sinus);
		co.attach(e);
		win1.attach(co);

		win1.resizable(win1);
		win1.show();

		std::cout << "loco\n";
		*/
		return N2B_run();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
}
