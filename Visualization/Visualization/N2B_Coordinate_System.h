#pragma once

#include <iostream>
#include <vector>

#include "N2B_Graphics.h"
#include "N2B_Box.h"

namespace N2B
{
	class N2B_Coordinate_System;
	class N2B_Function_Graph;
	/*
	N2B::Coordinate_System acts as a container
	for N2B::Function_Graphs and N2B::Shapes
	It also represents the x- and y-axis if is_visible is set true
	*/
	class N2B_Coordinate_System : public N2B_Box
	{
		friend class N2B_Function_Graph;
	private:
		double n_X, p_X, n_Y, p_Y;
		bool vis;
	public:
		N2B_Coordinate_System(int x, int y, int width, int height, double negative_X,
				double positive_X, double negative_Y, double positive_Y, bool is_visible = true)
			:N2B_Box(x, y, width, height), n_X(negative_X), p_X(positive_X)
						, n_Y(negative_Y), p_Y(positive_Y), vis(is_visible) {}

		//change axes visibility
		void set_visible(bool is_visible);
		void draw();
	};

	/*
	Function_Graph must be added to a 
	N2B::Coordinate_System to work.

	It contains a function pointer to a 
		double some_function(double)
	ore a
		int some_function(int)
	function.

	lambda function:
		auto some_function = [](int x) -> int 
		{
			return x * x;
		};
		N2B::Function_Graph some_graph(some_function);
	*/
	class N2B_Function_Graph : public N2B_Shape
	{
		friend class N2B_Coordinate_System;
	public:
		N2B_Function_Graph(int (*function)(int), N2B_Coordinate_System& root)
		:N2B_Shape(), intfunc(0), root(&root)
		{
			intfunc = function;
		}
	private:
		N2B_Coordinate_System* root;
		void draw();
		int(*intfunc)(int);
	};
}