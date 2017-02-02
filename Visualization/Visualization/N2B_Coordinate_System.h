#pragma once

#include <iostream>
#include <vector>

#include "N2B_Graphics.h"

namespace N2B
{
	class N2B_Coordinate_System;
	class N2B_Function_Graph;
	/*
	N2B::Coordinate_System acts as a container
	for N2B::Function_Graphs and N2B::Shapes
	It also represents the x- and y-axis if is_visible set true
	*/
	class N2B_Coordinate_System
	{
		friend class N2B_Function_Graph;
	private:
		double n_X, p_X, n_Y, p_Y;
		bool vis;
		std::vector<N2B_Shape> shapes;
		std::vector<N2B_Function_Graph> functions;
	public:
		N2B_Coordinate_System(double negative_X, double positive_X, double negative_Y, double positive_Y, bool is_visible = true)
			:n_X(negative_X), p_X(positive_X), n_Y(negative_Y), p_Y(positive_Y), vis(is_visible) {}
		
		//~N2B_Coordinate_System();

		//change axes visibility
		void set_visible(bool is_visible)
		{
			vis = is_visible;
		}

		//void add_Shape(N2B::Shape&);
		//void add_Function(N2B::Function_Graph&);

		//void del_Shape(int indx);
		//void del_Function(int indx);

		void draw()
		{
			for (int i = 0; i < shapes.size(); i++)
			{
				//shapes[i].draw();
			}
			for (int i = 0; i < functions.size(); i++)
			{
			}
		}
	};

	/*
	Function_Graph must be added to a 
	N2B::Coordinate_System to work.

	It contains a function pointer to a 
		double some_function(double)
	ore a
		int some_function(int)
	function.

	perfect with lambda functions like:
		auto some_function = [](int x) -> int 
		{
			return x * x;
		};
		N2B::Function_Graph some_graph(some_function);
	*/
	class N2B_Function_Graph
	{
		friend class N2B_Coordinate_System;
	public:
		//Function_Graph(){}

		N2B_Function_Graph(int (*function)(int))
		:intfunc(0)
		{
			intfunc = function;
			//DEBUG
			for (int x = 0; x < 10; x++)
			{
				std::cout << intfunc(x) << std::endl;
			}//END DEBUG
		}
		N2B_Function_Graph(double(*function)(double))
		:doublefunc(0)
		{
			doublefunc = function;
			//DEBUG
			for (double x = 0; x < 10; x += 0.5)
			{
				std::cout << doublefunc(x) << std::endl;
			}//END DEBUG
		}
	private:
		void draw()
		{

		}
		int(*intfunc)(int);
		double(*doublefunc)(double);
	};
}