/**
*N2B_Graphics.h
*Purpose:
Allows to create simple graphic elements
that know how to draw them selfe.

since v1.1
now with RGB colors

#TODO
-	make them resizable

@author Jordan
@version 1.1 04/23/17
*/

#pragma once
#define NB_GRAPHICS

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
	class NB_Color;

	enum NB_COLORS
	{
		NB_BLACK = FL_BLACK, NB_RED = FL_RED, NB_GREEN = FL_GREEN
		, NB_YELLOW = FL_YELLOW, NB_BLUE = FL_BLUE, NB_MAGENTA = FL_MAGENTA
		, NB_CYAN = FL_CYAN, NB_WHITE = FL_WHITE, NB_GRAY = FL_GRAY
	};

	class NB_Color
	{
	public:
		NB_Color()
			: color(NB_BLACK) {}

		NB_Color(NB_COLORS c)
			: color(c) {}

		NB_Color(Fl_Color c)
			: color(c) {}

		NB_Color& operator=(NB_Color& c)
		{
			this->color = c.color;
			return *this;
		}
		Fl_Color color;
	};
	NB_Color NB_rgb_color(uchar r, uchar g, uchar b);

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
		NB_Shape(NB_Color c = NB_BLACK)
			:color(c) {}
	public:
		NB_Color color;
		std::vector<NB_Point> points;
		NB_Shape(NB_Shape&);
		virtual void draw();

	protected:
		void add_Point(NB_Point& point);
		void del_Point(unsigned int idx);
		int size();
		NB_Point& operator[](std::size_t idx);
		const NB_Point& operator[](std::size_t idx) const;
	};

	class NB_Line : public NB_Shape
	{
	public:
		NB_Line(NB_Point point1, NB_Point point2, NB_Color c = NB_BLACK)
			: NB_Shape(c)
		{
			points.push_back(NB::NB_Point(point1));
			points.push_back(NB::NB_Point(point2));
		}
	};

	class NB_Polyline : public NB_Shape
	{
	public:
		template <class STLContainer>
		NB_Polyline(STLContainer& containerP, NB_Color c = NB_BLACK)
			: NB_Shape(c)
		{
			for (auto i : containerP)
			{
				this->points.push_back(NB::NB_Point(i));
			}
		}
		NB_Polyline(NB_Color c = NB_BLACK)
			: NB_Shape(c) {}

		void add_Point(NB_Point p) 
		{
			NB_Shape::add_Point(p);
		}
	};

	class NB_Mark : public NB_Shape
	{
	public:
		std::string m;
		NB_Mark(NB_Point point, std::string mark, NB_Color c = NB_BLACK)
			: NB_Shape(c), m(mark)
		{
			points.push_back(NB::NB_Point(point));
		}

	protected:
		void draw();
	};

	class NB_Rect : public NB_Shape
	{
	public:
		NB_Rect(NB_Point p, int width, int height, NB_Color c = NB_BLACK)
			: NB_Shape(c), width(width), height(height)
		{
			points.push_back(NB_Point(p));
		}
		int width;
		int height;
	private:
		void draw();
	};

	class NB_RectF : public NB_Shape
	{
	public:
		NB_RectF(NB_Point p, int width, int height, NB_Color c = NB_BLACK)
			: NB_Shape(c), width(width), height(height)
		{
			points.push_back(NB_Point(p));
		}
		int width;
		int height;
	private:
		void draw();
	};
}
