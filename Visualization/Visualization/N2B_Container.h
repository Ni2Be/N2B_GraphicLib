#pragma once

#include <vector>

#include <FL/Fl_Box.H>

#include "N2B_Coordinate_System.h"
#include "N2B_Graphics.h"


namespace N2B
{
	class N2B_Container //: public Fl_Box
	{
	private:
		std::vector<N2B_Shape> shapes;
		std::vector<N2B::N2B_Coordinate_System> coordinate_Systems;
	public:
		N2B_Container(int x, int y, int width, int height)
		{}

		void add_shape(N2B::N2B_Shape& shape)
		{
			shapes.push_back(shape);
		}

		void add_coordinate_System(N2B::N2B_Coordinate_System& coordinate_system)
		{
			//coordinate_Systems.push_back(coordinate_system);
		}

		void draw()
		{
			for (int i = 0; i < shapes.size(); i++)
			{
				shapes[i].draw();
			}
			for (int i = 0; i < coordinate_Systems.size(); i++)
			{
				//coordinate_Systems[i].draw();
			}
		}
	};
}