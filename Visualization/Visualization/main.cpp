#include <iostream>
#include <math.h>
#include <random>

#include "N2B_Window.h"
#include "N2B_Box.h"
#include "N2B_Graphics.h"
#include "N2B_Coordinate_System.h"

#include "Test_Window_Coordinate_System_v1.h"
#include "Test_Window_Coordinate_System_v2.h"
#include "Test_Window_Event.h"

using namespace NB;
using namespace Test;
int main()
{
	try
	{
		Test_Window_Event event_test;
		event_test.show();

		Test_Window_Coordinate_System_v1 coordinate_test_v1;
		coordinate_test_v1.show();

		Test_Window_Coordinate_System_v2 coordinate_test_v2;
		coordinate_test_v2.show();

		return NB_run();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
}
