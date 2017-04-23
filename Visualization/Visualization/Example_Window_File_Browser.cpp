#include "Example_Window_File_Browser.h"


void Example::Example_Window_File_Browser::cb_open(Fl_Widget* w, void* window)
{
	auto o = static_cast<Example::Example_Window_File_Browser*> (window);
	o->open();
}

void Example::Example_Window_File_Browser::open()
{
	//show browser
	if (file_browser.show() == 0)
	{
		// Print all filenames user selected
		for (int n = 0; n < file_browser.count(); n++)
		{
			buff.append(file_browser.filename(n));
			buff.append("\n");
		}
	}
}
