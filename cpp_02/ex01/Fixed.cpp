#include "Fixed.hpp"


Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value)
{
	std::cout << "Parameterised constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(value)
{
	here help me
	std::cout << "Parameterised constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _value(other._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_value = other._value;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits (void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits (int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float toFloat (void) const
{
	here help me
}

int toInt (void) const
{
	here help me
}

