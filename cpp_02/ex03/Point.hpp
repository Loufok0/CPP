#pragma once

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:

		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		Point& operator=(const Point &other);
		~Point();

		float getX(void) const;
		float getY(void) const;

};

	bool bsp( Point const a, Point const b, Point const c, Point const point);
	std::ostream&	operator << (std::ostream &os, const Point& p);
