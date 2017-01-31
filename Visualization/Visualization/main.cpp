#include <iostream>
#include <FL/Fl.H>

#include "N2B_Graphics.h"

int main()
{
	try
	{
		N2B::Polyline pl1(N2B::Point(0, 0));
		pl1.add_Point(N2B::Point(3, 3));
		pl1.add_Point(N2B::Point(5, 9));
		pl1.add_Point(N2B::Point(3, 6));

		std::cout << "\nP0:" << pl1[0].x << "\nP1:" << pl1[1].x << "\nP2:" << pl1[2].x << "\nP3:" << pl1[3].x;
		pl1.del_Point(1);
		pl1.del_Point(2);
		std::cout << "\n\nP0:" << pl1[0].x << "\nP1:" << pl1[1].x << "\nSize:" << pl1.size();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	char ch;
	std::cin >> ch;
	return 0;
}