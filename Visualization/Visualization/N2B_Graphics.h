
#pragma once

#define N2B_GRAPHICS

#include "N2B_Include.h"
#include <iostream>

//Visual Studio 2015
#ifdef _DEBUG
#define DEBUG
#endif // _DEBUG

namespace N2B
{
	class N2B_Point;
	class N2B_Shape;
	class N2B_Line;
	class N2B_Ployline;
	class N2B_Mark;

	class N2B_Point
	{
	public:
		int x;
		int y;

		N2B_Point()
			:x(0), y(0) {}
		N2B_Point(int x, int y)
			:x(x), y(y) {}

		N2B_Point& operator=(const N2B_Point& other);
		N2B_Point(const N2B_Point& point);
	};
	inline bool operator==(const N2B_Point& lhs, const N2B_Point& rhs);

	enum N2B_Color
	{
		N2B_BLACK = FL_BLACK, N2B_RED = FL_RED, N2B_GREEN = FL_GREEN
		, N2B_YELLOW = FL_YELLOW, N2B_BLUE = FL_BLUE, N2B_MAGENTA = FL_MAGENTA
		, N2B_CYAN = FL_CYAN, N2B_WHITE = FL_WHITE, N2B_GRAY = FL_GRAY
	};

	class N2B_Shape
	{
	protected:
		N2B_Color color;
		std::vector<N2B_Point> points;
	public:
		N2B_Shape()
			:color(N2B_BLACK) {}

		N2B_Shape(N2B_Shape&);
		virtual void draw();
	};

	class N2B_Line : public N2B_Shape
	{
	public:
		N2B_Line(N2B_Point point1, N2B_Point point2)
			: N2B_Shape()
		{
			points.push_back(N2B::N2B_Point(point1));
			points.push_back(N2B::N2B_Point(point2));
		}
	};

	class Polyline : public N2B_Shape
	{
	public:
		Polyline(N2B_Point p0)
			: N2B_Shape()
		{
			points.push_back(N2B::N2B_Point(p0));
		}
		void add_Point(N2B_Point& point);
		void del_Point(int idx);
		int size();
		N2B_Point& operator[](std::size_t idx);
		const N2B_Point& operator[](std::size_t idx) const;
	};

	class N2B_Mark : public N2B_Shape
	{
	public:
		std::string m;
		N2B_Mark(N2B_Point point, std::string mark)
			: N2B_Shape(), m(mark)
		{
			points.push_back(N2B::N2B_Point(point));
		}

	protected:
		void draw();
	};
}
