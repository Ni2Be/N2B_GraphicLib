/**
*Example_Window_File_Browser.h
*Purpose:
An Example that shows how to open a file
and how to plot it into a text display

@author Jordan
@version 1.0 04/22/17
*/

#pragma once
#include "N2B_Window.h"

#include <Fl/Fl_Button.H>
#include <Fl/Fl_Native_File_Chooser.H>
#include <Fl/Fl_Text_Display.H>
#include <iostream>

namespace Example
{
	using namespace NB;
	class Example_Window_File_Browser : public NB_Window
	{
	public:
		Example_Window_File_Browser()
			:NB_Window(400, 400, "File Browser"),
			btn_open(150, 5, 100, 25, "Open"),
			disp(10, 40, 380, 350)
		{
			file_browser.title("Pick a file");
			file_browser.type(Fl_Native_File_Chooser::BROWSE_MULTI_FILE);
			this->end();

			disp.buffer(buff);
			btn_open.callback(cb_open, this);
		}
	private:
		Fl_Text_Buffer buff; 
		Fl_Text_Display disp;
		Fl_Native_File_Chooser file_browser;
		Fl_Button btn_open;

		static void cb_open(Fl_Widget* w, void* window);
		void open();
	};
}
