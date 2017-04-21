/**
*N2B_Include.h
*Purpose:
Includes used FLTK libs,
also defines importent static functions

#TODO
-	make them resizable

@author Jordan
@version 1.0 04/21/17
*/
#pragma once

#include <vector>

//FLTK 1.3.4
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>

#include <FL/fl_draw.H>

namespace NB
{
	static int NB_run()
	{
		return Fl::run();
	}
}