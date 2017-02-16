/*
#pragma once

#define N2B_GRAPHICS

#include "N2B_Include.h"

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
			:x(0), y(0){}
		N2B_Point(int x, int y)
			:x(x), y(y) {}

		N2B_Point& operator=(const N2B_Point& other)
		{
#ifdef DEBUG
			if (this == &other)
			{
				throw std::runtime_error("\nclass Point\nPoint& operator=(Point other):\nSelf assignment");
			}
#endif // DEBUG
			x = other.x;
			y = other.y;
			return *this;
		}
		N2B_Point(const N2B_Point& point)
		{
			*this = point;
		}
	};
	inline bool operator==(const N2B_Point& lhs, const N2B_Point& rhs)
	{
		return (lhs.x == rhs.x && lhs.y == rhs.y);
	}

	enum N2B_Color 
	{	N2B_BLACK = FL_BLACK, N2B_RED = FL_RED, N2B_GREEN = FL_GREEN
		, N2B_YELLOW = FL_YELLOW, N2B_BLUE = FL_BLUE, N2B_MAGENTA = FL_MAGENTA
		, N2B_CYAN = FL_CYAN, N2B_WHITE = FL_WHITE, N2B_GRAY = FL_GRAY
	};

	class N2B_Shape
	{
	protected:
		N2B_Shape() 
		:color(N2B_BLACK) {}

		N2B_Color color;
		std::vector<N2B_Point> points;
	public:
		virtual void draw() {}
	};

	class N2B_Line : public N2B_Shape
	{
	public:
		N2B_Line(N2B_Point point1, N2B_Point point2)
			:N2B_Shape()
		{
			points.push_back(point1);
			points.push_back(point2);
		}
		N2B_Point& p1()
		{
			return points[0];
		}
		N2B_Point& p2()
		{
			return points[1];
		}
		void p1(const N2B_Point& point)
		{
			points[0] = point;
		}
		void p2(const N2B_Point& point)
		{
			points[1] = point;
		}
	protected:
		void draw()
		{}
	};

	class Polyline : public N2B_Shape
	{
	private:
		int point_count;
	public:
		Polyline(const N2B_Point& p0)
			:point_count(0)
		{
			points.push_back(p0);
			point_count++;
		}
		void add_Point(N2B_Point& point)
		{
			points.push_back(point);
			point_count++;
		}
		void del_Point(int idx)
		{
#ifdef DEBUG
			if (idx >= points.size() || idx < 0)
			{
				throw std::runtime_error("\nclass Polyline\del_Point(int idx):\nout of bounds");
			}
#endif // DEBUG
			points.erase(points.begin() + idx, points.begin() + idx + 1);
			point_count--;
		}
		int size()
		{
			return point_count;
		}
		N2B_Point& operator[](std::size_t idx)
		{
#ifdef DEBUG
			if (idx >= points.size() || idx < 0)
			{
				throw std::runtime_error("\nclass Polyline\noperator[]:\nout of bounds");
			}
#endif // DEBUG
			return points[idx];
		}
		const N2B_Point& operator[](std::size_t idx) const
		{
#ifdef DEBUG
			if (idx >= points.size() || idx < 0)
			{
				throw std::runtime_error("\nclass Polyline\nconst operator[]:\nout of bounds");
			}
#endif // DEBUG
			return points[idx];
		}

	protected:
		void draw()
		{

		}
	};

	class N2B_Mark : public N2B_Shape
	{
	public:
		char m;
		N2B_Mark(const N2B_Point& point, const char& mark = 'x')
			:m(mark)
		{
			points.push_back(point);
		}

	protected:
		void draw()
		{

		}
	};
}
*/