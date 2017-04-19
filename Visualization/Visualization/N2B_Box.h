#pragma once

#define N2B_BOX
#include <memory>
#include "N2B_Include.h"

#include "N2B_Graphics.h"

namespace NB
{
	class NB_Box
	{
	protected:
		int x;
		int y;
		int width;
		int height;
		double width_percentage;
		double height_percentage;
		double x_percentage;
		double y_percentage;
		//N2B_Color background;
		//std::vector<N2B_Box*> boxes;
		std::vector<NB_Shape*> shapes;
	public:
		NB_Box(int x, int y, int width, int height)
			:x(x), y(y), width(width), height(height) {}
		~NB_Box();
		virtual void draw();


		template <class AShape>
		void add(AShape& shape)
		{
			std::unique_ptr<AShape> sh(new AShape(shape));
			this->shapes.push_back(sh.release());
		}
	};
}