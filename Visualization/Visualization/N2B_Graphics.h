#pragma once
//std c++
#include <vector>

//FLTK 1.3.4
#include <FL/fl_draw.H>

//Visual Studio 2015
#ifdef _DEBUG
#define DEBUG
#endif // _DEBUG

namespace N2B
{
	class Point;
	class Color;
	class Shape;
	class Line;
	class Ployline;
	class Mark;

	class Point
	{
	public:
		int x;
		int y;

		Point()
			:x(0), y(0){}
		Point(int x, int y)
			:x(x), y(y) {}

		Point& operator=(const Point& other)
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
		Point(const Point& point)
		{
			*this = point;
		}
	};
	inline bool operator==(const Point& lhs, const Point& rhs)
	{
		return (lhs.x == rhs.x && lhs.y == rhs.y);
	}

	class Color
	{
		friend class Shape;
	public:
		const static int BLACK = FL_BLACK;
		const static int RED = FL_RED;
		const static int GREEN = FL_GREEN;
		const static int YELLOW = FL_YELLOW;
		const static int BLUE = FL_BLUE;
		const static int MAGENTA = FL_MAGENTA;
		const static int CYAN = FL_CYAN;
		const static int WHITE = FL_WHITE;
		const static int GRAY = FL_GRAY;

		Color(int color)
		: c(color) {}
	private:
		Fl_Color c;

		Color()
		: c(BLACK) {}
	};

	class Shape
	{
	protected:
		Shape() {}
		Color color;
		std::vector<Point> points;
	public:
		//virtual void draw();
	};

	class Line : Shape
	{
	public:
		Line(const Point& point1, const Point& point2)
		{
			points.push_back(point1);
			points.push_back(point2);
		}
		Point& p1()
		{
			return points[0];
		}
		Point& p2()
		{
			return points[1];
		}
		void p1(const Point& point)
		{
			points[0] = point;
		}
		void p2(const Point& point)
		{
			points[1] = point;
		}
	};

	class Polyline : Shape
	{
	private:
		int point_count;
	public:
		Polyline(const Point& p0)
			:point_count(0)
		{
			points.push_back(p0);
			point_count++;
		}
		void add_Point(Point& point)
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
		Point& operator[](std::size_t idx)
		{
#ifdef DEBUG
			if (idx >= points.size() || idx < 0)
			{
				throw std::runtime_error("\nclass Polyline\noperator[]:\nout of bounds");
			}
#endif // DEBUG
			return points[idx];
		}
		const Point& operator[](std::size_t idx) const
		{
#ifdef DEBUG
			if (idx >= points.size() || idx < 0)
			{
				throw std::runtime_error("\nclass Polyline\nconst operator[]:\nout of bounds");
			}
#endif // DEBUG
			return points[idx];
		}
	};

	class Mark : Shape
	{
		char m;
		Mark(const Point& point, const char& mark = 'x')
			:m(mark)
		{
			points.push_back(point);
		}
	};
}