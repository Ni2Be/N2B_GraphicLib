/**
*N2B_Coordinate_System.h
*Purpose:
Allows to display a function on a NB_Window

#TODO
-	if the system axis are in the left the function
	is not drawn properly
-	make it resizable

@author Jordan
@version 0.1 04/21/17
*/
#pragma once

#include <iostream>
#include <vector>

#include "N2B_Graphics.h"
#include "N2B_Box.h"

namespace NB
{
	class NB_Coordinate_System;
	class NB_Function_Graph;

	/**
	A NB_Function_Graph must be added to a
	NB_Coordinate_System to work.

	Example in Test_Window_Coordinate_System_v1,
	Test_Window_Coordinate_System_v2.
	@see NB::NB_Coordinate_System
	@see Test::Test_Window_Coordinate_System_v1
	@see Test::Test_Window_Coordinate_System_v2
	*/
	class NB_Function_Graph
	{
		friend class NB_Coordinate_System;
	public:
		NB_Function_Graph(double(*function)(double), NB_Color c = NB_BLACK)
			:func(0), color(c)
		{
			func = function;
		}
	private:
		NB_Color color;
		NB_Coordinate_System* root;//the coordinate system that the function_graph is atteched to
		void draw();

		/**
		The function that will be displayed
		@param x
		@return f(x)
		@see NB::Coordinate_System
		*/
		double(*func)(double);
	};

	/**
	A NB_Coordinate_System acts as a container
	for NB_Function_Graphs and NB::NB_Shapes.

	It also represents the x- and y-axis, and
	shows lines at full integers if is_vis is set true

	Example in Test_Window_Coordinate_System_v1 and
	Test_Window_Coordinate_System_v2.
	@see NB::NB_Function_Graphs
	@see Test::Test_Window_Coordinate_System_v1
	@see Test::Test_Window_Coordinate_System_v2
	*/
	class NB_Coordinate_System : public NB_Box
	{	
		friend class NB_Function_Graph;
	private:
		double neg_x, pos_x, neg_y, pos_y;
		std::vector<NB_Function_Graph*> graphs;
	public:
		bool is_vis;
		NB_Color color;
		int x_axis, y_axis;

		NB_Coordinate_System(int x, int y, int width, int height,
			double negative_X, double positive_X, double negative_Y, double positive_Y,
			bool is_visible = true, NB_Color c = NB_BLACK)
			:NB_Box(x, y, width, height), neg_x(negative_X), pos_x(positive_X), x_axis(x_axis), y_axis(y_axis)
			, neg_y(negative_Y), pos_y(positive_Y), is_vis(is_visible), color(c) 
		{
			x_axis = height / 2;
			y_axis = width / 2;
			if (negative_X >= 0 || negative_Y >= 0)
				throw std::runtime_error("\nclass NB_Coordinate_System\nNB_Coordinate_System():\nWrong x, or y\n");
			if (positive_X <= 0 || positive_Y <= 0)
				throw std::runtime_error("\nclass NB_Coordinate_System\nNB_Coordinate_System():\nWrong x, or y\n");
		}

		void set_nX(double);
		void set_nY(double);
		void set_pX(double);
		void set_pY(double);

		double get_nX() { return neg_x; }
		double get_nY() { return neg_y; }
		double get_pX() { return pos_x; }
		double get_pY() { return pos_y; }

		//change axes visibility
		void set_visible(bool is_visible);
		void draw();


		template <class AShape>
		void attach(AShape& shape)
		{
			this->boxes.push_back(&box);
			box.root = this;
		}

		template <>
		void attach<NB_Function_Graph>(NB_Function_Graph& func)
		{
			this->graphs.push_back(&func);
			func.root = this;
		}

		template <class AShape>
		void detach(AShape& shape)
		{
			shapes.erase(std::find(shapes.begin(), shapes.end(), &shape));
		}

		template <>
		void detach<NB_Function_Graph>(NB_Function_Graph& func)
		{
			graphs.erase(std::find(graphs.begin(), graphs.end(), &func));
		}
	};
}