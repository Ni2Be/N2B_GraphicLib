#include <iostream>
#include <math.h>
#include <random>

#include "N2B_Window.h"
#include "N2B_Box.h"
#include "N2B_Graphics.h"
#include "N2B_Coordinate_System.h"

#include "Example_Window_Coordinate_System_v1.h"
#include "Example_Window_Coordinate_System_v2.h"
#include "Example_Window_Event.h"
#include "Example_Window_File_Browser.h"

using namespace NB;
using namespace Example;
int main()
{
	try
	{
		Example_Window_File_Browser file_test;
		file_test.show();

		Example_Window_Event event_test;
		event_test.resizable(&event_test);
		event_test.show();

		Example_Window_Coordinate_System_v1 coordinate_test_v1;
		coordinate_test_v1.resizable(&coordinate_test_v1);
		coordinate_test_v1.show();

		Example_Window_Coordinate_System_v2 coordinate_test_v2;
		coordinate_test_v2.resizable(&coordinate_test_v2);
		coordinate_test_v2.show();

		return NB_run();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
}
