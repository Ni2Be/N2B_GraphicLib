#pragma once

#define N2B_BOX
#include "N2B_Include.h"

namespace N2B
{
	class N2B_Box
	{
	private:
		double width_percentage;
		double height_percentage;
		double x_percentage;
		double y_percentage;
		//N2B_Color background;
		//std::vector<N2B_Box&> boxes;
		//std::vector<N2B_Shape&> shapes;
	public:
		N2B_Box(int x, int y, int width, int height)
			{}

		void draw() {}
	};
}