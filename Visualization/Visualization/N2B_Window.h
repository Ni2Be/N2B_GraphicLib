#pragma once

#define N2B_WINDOW
#include "N2B_Include.h"
#include "N2B_Box.h"

namespace N2B
{
	class N2B_Window : public Fl_Double_Window
	{
	public:
		N2B_Window(int width, int height, const char* title = "")
			:Fl_Double_Window(width, height, title) {}
		~N2B_Window();

		void attatch(N2B_Box& box);
		void draw();

		template <class ABox>
		void add(ABox& shape)
		{
			std::unique_ptr<ABox> bo(new ABox(shape));
			this->boxes.push_back(bo.release());
		}
	private:
		std::vector<N2B_Box*> boxes;
	};


}