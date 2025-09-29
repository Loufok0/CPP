#include "Point.hpp"

float Area(Point const &a, Point const &b, Point const &c)
{
	float A = std::sqrt(std::pow((a.getX() - b.getX()), 2) + std::pow((a.getY() - b.getY()), 2));
	float B = std::sqrt(std::pow((b.getX() - c.getX()), 2) + std::pow((b.getY() - c.getY()), 2));
	float C = std::sqrt(std::pow((c.getX() - a.getX()), 2) + std::pow((c.getY() - a.getY()), 2));
	float S = (A + B + C) / 2.0;

	return (std::sqrt(S * (S - A) * (S - B) * (S - C)) < 1e-6);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{

	if ((a.getX() == point.getX() && a.getY() == point.getY()) || 
		(b.getX() == point.getX() && b.getY() == point.getY()) || 
		(c.getX() == point.getX() && c.getY() == point.getY()) )
		return (false);

	float A = Area(a, b, c);
	float A1= Area(point, b, c);
	float A2 = Area(a, point, c);
	float A3 = Area(a, b, point);
	
	return (A == (A1 + A2 + A3));
}
