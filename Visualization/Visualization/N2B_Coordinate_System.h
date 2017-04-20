#pragma once

#include <iostream>
#include <vector>

#include "N2B_Graphics.h"
#include "N2B_Box.h"

namespace NB
{
	class NB_Coordinate_System;
	class NB_Function_Graph;

	/*
	Function_Graph must be added to a
	N2B::Coordinate_System to work.
	co_sy.add(N2B_Function_Graph((sin_function), co_sy));

		auto some_function = [](int x) -> int
		{
			return x * x;
		};
		N2B::Function_Graph some_graph(some_function);
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
		NB_Coordinate_System* root;
		void draw();
		double(*func)(double);
	};

	/*
	N2B::Coordinate_System acts as a container
	for N2B::Function_Graphs and N2B::Shapes
	It also represents the x- and y-axis if is_vis is set true
	*/
	class NB_Coordinate_System : public NB_Box
	{
		friend class NB_Function_Graph;
	private:
		double n_X, p_X, n_Y, p_Y;
		NB_Color color;
		bool is_vis;
		std::vector<NB_Function_Graph*> functions;
	public:
		int x_axis, y_axis;
		NB_Coordinate_System(int x, int y, int width, int height,
			double negative_X, double positive_X, double negative_Y, double positive_Y,
			bool is_visible = true, NB_Color c = NB_BLACK)
			:NB_Box(x, y, width, height), n_X(negative_X), p_X(positive_X), x_axis(x_axis), y_axis(y_axis)
			, n_Y(negative_Y), p_Y(positive_Y), is_vis(is_visible), color(c) 
		{
			x_axis = height / 2;
			y_axis = width / 2;
			if (negative_X >= 0 || negative_Y >= 0)
				throw std::runtime_error("\nclass NB_Coordinate_System\NB_Coordinate_System():\nWrong x, or y\n");
			if (positive_X <= 0 || positive_Y <= 0)
				throw std::runtime_error("\nclass NB_Coordinate_System\NB_Coordinate_System():\nWrong x, or y\n");
		}

		void set_nX(double);
		void set_nY(double);
		void set_pX(double);
		void set_pY(double);

		double get_nX() { return n_X; }
		double get_nY() { return n_Y; }
		double get_pX() { return p_X; }
		double get_pY() { return p_Y; }

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
			this->functions.push_back(&func);
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
			functions.erase(std::find(functions.begin(), functions.end(), &func));
		}

	};
}