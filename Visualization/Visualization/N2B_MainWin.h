#pragma once

//FLTK 1.3.4
#include <FL/Fl_Double_Window.H>

namespace N2B
{
	class N2B_Window : public Fl_Double_Window
	{
	public:
		N2B_Window(int width, int height, const char* title = "")
			:Fl_Double_Window(width, height, title) {}

		void add_Container(N2B::N2B_Container& container)
		{
			contains.push_back(container);
		}

		void draw() 
		{
			Fl_Double_Window::draw();
			for (int i = 0; i < contains.size(); i++)
			{
				contains[i].draw();
			}
		}

		void redraw()
		{
			Fl_Double_Window::redraw();
			for (int i = 0; i < contains.size(); i++)
			{
				contains[i].draw();
			}
		}

	private:
		std::vector<N2B::N2B_Container> contains;
	};

	static int N2B_run()
	{
		return Fl::run();
	}
}