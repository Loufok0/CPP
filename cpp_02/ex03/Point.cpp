#include "Point.hpp"


Point::Point() : _x(Fixed(0)), _y(Fixed(0))
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
	// std::cout << "Parameterised constructor called" << std::endl;
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	(void)other;
	return (*this);
}

Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}

std::ostream&	operator << (std::ostream &os, const Point& p)
{
	os << "x: " << p.getX() << "\t" << "y: " << p.getY();
	return (os);
}

float Point::getX(void) const
{
	return (this->_x.toFloat());
}

float Point::getY(void) const
{
	return (this->_y.toFloat());
}
