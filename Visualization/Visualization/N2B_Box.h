#pragma once

#define N2B_BOX
#include <memory>
#include "N2B_Include.h"

#include "N2B_Graphics.h"

namespace NB
{
	class NB_Box
	{
		friend class NB_Window;
	protected:
		int x;
		int y;
		int width;
		int height;
		double width_percentage;
		double height_percentage;
		double x_percentage;
		double y_percentage;

		std::vector<NB_Box*> boxes;
		//std::vector<NB_Shape*> owned_shapes;
		std::vector<NB_Shape*> shapes;
		NB_Window* root;
		NB_Box* root_b;

	public:
		NB_Box(int x, int y, int width, int height)
			:x(x), y(y), width(width), height(height) {}
		~NB_Box();
		virtual void draw();

		template <class AShape>
		void attach(AShape& shape)
		{
			this->shapes.push_back(&shape);
		}

		template <>
		void attach<NB_Box>(NB_Box& box)
		{
			this->boxes.push_back(&box);
			box.root_b = this;
		}

		template <class AShape>
		void detach(AShape& shape)
		{
			shapes.erase(std::find(shapes.begin(), shapes.end(), &shape));
		}

		template <>
		void detach<NB_Box>(NB_Box& box)
		{
			boxes.erase(std::find(boxes.begin(), boxes.end(), &box));
		}

		/* not used
		template <class AShape>
		void add(AShape& shape)
		{
			std::unique_ptr<AShape> sh(new AShape(shape));
			this->owned_shapes.push_back(sh.release());
		}
		*/
	};
}