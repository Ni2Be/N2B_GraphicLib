#include "N2B_Graphics.h"


NB::NB_Shape::NB_Shape(NB_Shape& s)
{
	this->color = s.color;
	this->points.resize(s.points.size());
	std::copy(s.points.begin(), s.points.end(), this->points.begin());
}

void NB::NB_Shape::draw()
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


NB::NB_Point& NB::NB_Point::operator=(const NB_Point& other)
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

NB::NB_Point::NB_Point(const NB::NB_Point& point)
{
	this->x = point.x;
	this->y = point.y;
}

inline bool NB::operator==(const NB::NB_Point& lhs, const NB::NB_Point& rhs)
{
	return (lhs.x == rhs.x && lhs.y == rhs.y);
}

void NB::Polyline::add_Point(NB_Point& point)
{
	points.push_back(point);
}

void NB::Polyline::del_Point(int idx)
{
#ifdef DEBUG
	if (idx >= points.size() || idx < 0)
	{
		throw std::runtime_error("\nclass Polyline\del_Point(int idx):\nout of bounds");
	}
#endif // DEBUG
	points.erase(points.begin() + idx, points.begin() + idx + 1);
}

int NB::Polyline::size()
{
	return points.size();
}

NB::NB_Point& NB::Polyline::operator[](std::size_t idx)
{
#ifdef DEBUG
	if (idx >= points.size() || idx < 0)
	{
		throw std::runtime_error("\nclass Polyline\noperator[]:\nout of bounds");
	}
#endif // DEBUG
	return points[idx];
}
const NB::NB_Point& NB::Polyline::operator[](std::size_t idx) const
{
#ifdef DEBUG
	if (idx >= points.size() || idx < 0)
	{
		throw std::runtime_error("\nclass Polyline\nconst operator[]:\nout of bounds");
	}
#endif // DEBUG
	return points[idx];
}

void NB::NB_Mark::draw()
{
	fl_color(FL_BLACK);
	fl_font(FL_HELVETICA, 16);
	fl_draw(m.c_str(), points[0].x - 4, points[0].y + 4);
}