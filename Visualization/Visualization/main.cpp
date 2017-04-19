#include <iostream>
#include <math.h>

#include "N2B_Window.h"
#include "N2B_Box.h"
#include "N2B_Graphics.h"
#include "N2B_Coordinate_System.h"

using namespace NB;
int main()
{
	try
	{
		NB_Window win1(400, 400, "win1");
		NB_Box b1(0, 0, 200, 200);
		b1.add(NB_Line(NB_Point(20, 20), NB_Point(220, 120)));
		b1.add(NB_Mark(NB_Point(20, 20), "x"));
		win1.attatch(b1);

		NB_Coordinate_System co(0, 0, 400, 400, -3, 5, -2, 5, true);

		auto sin_function = [](double x) -> double
		{
			return std::sin(x);
		};
		co.add(NB_Function_Graph(sin_function));

		auto exp_function = [](double x) -> double
		{
			return std::pow(x, 2) + 0.6;
		};
		co.add(NB_Function_Graph(exp_function));
		win1.attatch(co);


		win1.resizable(win1);
		win1.show();

		return N2B_run();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
}
