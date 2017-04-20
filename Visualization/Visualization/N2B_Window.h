#pragma once

#define N2B_WINDOW
#include "N2B_Include.h"
#include "N2B_Box.h"

namespace NB
{
	class NB_Window : public Fl_Double_Window
	{
	public:
		NB_Window(int width, int height, const char* title, NB_Color c = NB_WHITE)
			:Fl_Double_Window(width, height, title) 
		{
			this->color(c);
		}
		void attach(NB_Box& box);
		void draw();
	private:
		std::vector<NB_Box*> boxes;
	};
}