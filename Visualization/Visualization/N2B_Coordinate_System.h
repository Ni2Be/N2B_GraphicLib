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
		NB_Function_Graph(double(*function)(double))
			:func(0)
		{
			func = function;
		}
	private:
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
		bool is_vis;
		std::vector<NB_Function_Graph*> functions;
	public:
		NB_Coordinate_System(int x, int y, int width, int height,
			double negative_X, double positive_X, double negative_Y, double positive_Y,
			bool is_visible = true)
			:NB_Box(x, y, width, height), n_X(negative_X), p_X(positive_X)
			, n_Y(negative_Y), p_Y(positive_Y), is_vis(is_visible) {}

		//change axes visibility
		void set_visible(bool is_visible);
		void draw();


		template <class AShape>
		void add(AShape& shape)
		{
			std::unique_ptr<AShape> sh(new AShape(shape));
			this->shapes.push_back(sh.release());
		}

		template <>
		void add<NB_Function_Graph>(NB_Function_Graph& fct)
		{
			std::unique_ptr<NB_Function_Graph> f(new NB_Function_Graph(fct));
			f->root = this;
			this->functions.push_back(f.release());
		}
	};
}