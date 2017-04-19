
#pragma once

#define N2B_GRAPHICS

#include "N2B_Include.h"
#include <iostream>

//Visual Studio 2015
#ifdef _DEBUG
#define DEBUG
#endif // _DEBUG

namespace NB
{
	class NB_Point;
	class NB_Shape;
	class NB_Line;
	class NB_Ployline;
	class NB_Mark;

	enum NB_Color
	{
		NB_BLACK = FL_BLACK, NB_RED = FL_RED, NB_GREEN = FL_GREEN
		, NB_YELLOW = FL_YELLOW, NB_BLUE = FL_BLUE, NB_MAGENTA = FL_MAGENTA
		, NB_CYAN = FL_CYAN, NB_WHITE = FL_WHITE, NB_GRAY = FL_GRAY
	};

	class NB_Point
	{
	public:
		int x;
		int y;

		NB_Point()
			:x(0), y(0) {}
		NB_Point(int x, int y)
			:x(x), y(y) {}

		NB_Point& operator=(const NB_Point& other);
		NB_Point(const NB_Point& point);
	};
	inline bool operator==(const NB_Point& lhs, const NB_Point& rhs);

	class NB_Shape
	{
	protected:
		NB_Color color;
		std::vector<NB_Point> points;
	public:
		NB_Shape()
			:color(NB_BLACK) {}

		NB_Shape(NB_Shape&);
		virtual void draw();
	};

	class NB_Line : public NB_Shape
	{
	public:
		NB_Line(NB_Point point1, NB_Point point2)
			: NB_Shape()
		{
			points.push_back(NB::NB_Point(point1));
			points.push_back(NB::NB_Point(point2));
		}
	};

	class Polyline : public NB_Shape
	{
	public:
		Polyline(NB_Point p0)
			: NB_Shape()
		{
			points.push_back(NB::NB_Point(p0));
		}
		void add_Point(NB_Point& point);
		void del_Point(int idx);
		int size();
		NB_Point& operator[](std::size_t idx);
		const NB_Point& operator[](std::size_t idx) const;
	};

	class NB_Mark : public NB_Shape
	{
	public:
		std::string m;
		NB_Mark(NB_Point point, std::string mark)
			: NB_Shape(), m(mark)
		{
			points.push_back(NB::NB_Point(point));
		}

	protected:
		void draw();
	};
}
