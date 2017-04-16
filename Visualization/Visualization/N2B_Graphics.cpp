#include "N2B_Graphics.h"


N2B::N2B_Shape::N2B_Shape(N2B_Shape& s)
{
	this->color = s.color;
	this->points.resize(s.points.size());
	std::copy(s.points.begin(), s.points.end(), this->points.begin());
}

void N2B::N2B_Shape::draw()
{
	fl_color(FL_BLACK);
	if (this->points.size() > 1)
	{
		for (int i = 1; i < this->points.size(); i++)
		{
			fl_line(points[i - 1].x, points[i - 1].y, points[i].x, points[i].y);
		}
	}
}


N2B::N2B_Point& N2B::N2B_Point::operator=(const N2B_Point& other)
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

N2B::N2B_Point::N2B_Point(const N2B::N2B_Point& point)
{
	this->x = point.x;
	this->y = point.y;
}

inline bool N2B::operator==(const N2B::N2B_Point& lhs, const N2B::N2B_Point& rhs)
{
	return (lhs.x == rhs.x && lhs.y == rhs.y);
}

void N2B::Polyline::add_Point(N2B_Point& point)
{
	points.push_back(point);
}

void N2B::Polyline::del_Point(int idx)
{
#ifdef DEBUG
	if (idx >= points.size() || idx < 0)
	{
		throw std::runtime_error("\nclass Polyline\del_Point(int idx):\nout of bounds");
	}
#endif // DEBUG
	points.erase(points.begin() + idx, points.begin() + idx + 1);
}

int N2B::Polyline::size()
{
	return points.size();
}

N2B::N2B_Point& N2B::Polyline::operator[](std::size_t idx)
{
#ifdef DEBUG
	if (idx >= points.size() || idx < 0)
	{
		throw std::runtime_error("\nclass Polyline\noperator[]:\nout of bounds");
	}
#endif // DEBUG
	return points[idx];
}
const N2B::N2B_Point& N2B::Polyline::operator[](std::size_t idx) const
{
#ifdef DEBUG
	if (idx >= points.size() || idx < 0)
	{
		throw std::runtime_error("\nclass Polyline\nconst operator[]:\nout of bounds");
	}
#endif // DEBUG
	return points[idx];
}

void N2B::N2B_Mark::draw()
{
	fl_color(FL_BLACK);
	fl_font(FL_HELVETICA, 16);
	fl_draw(m.c_str(), points[0].x - 4, points[0].y + 4);
}