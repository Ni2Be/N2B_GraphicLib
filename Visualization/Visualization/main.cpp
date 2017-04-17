#include <iostream>
#include <math.h>

#include "N2B_Window.h"
#include "N2B_Box.h"
#include "N2B_Graphics.h"
#include "N2B_Coordinate_System.h"

using namespace N2B;
int main() 
{
	try 
	{
		N2B_Window win1(400, 400, "win1");
		//N2B_Box b1(0, 0, 200, 200);
		//b1.add(N2B_Line(N2B_Point(20, 20), N2B_Point(220, 120)));
		//b1.add(N2B_Mark(N2B_Point(20, 20), "x"));
		//win1.attatch(b1);
		
		N2B_Coordinate_System co(0, 0, 400, 400, 0, 0, 0, 0, true);

		auto sin_function = [](int x) -> int
		{
			return std::sin(x) * 10;
		};
		//co.add(N2B_Function_Graph((sin_function), co));

		auto exp_function = [](int x) -> int
		{
			return std::pow(x, 6) * 0.001 - std::pow(x, 4) * 0.01 + x - 25;
		};
		co.add(N2B_Function_Graph((exp_function), co));
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
