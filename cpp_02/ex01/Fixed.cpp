#include "Fixed.hpp"


Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Parameterised constructor called" << std::endl;
	_value = value;
}

Fixed::Fixed(const float value)
{
	std::cout << "Parameterised constructor called" << std::endl;
	_value = (value * (1 << _width));
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



float Fixed::toFloat (void) const
{
	return (static_cast<float>(_value) / (1 << _width));
}

int Fixed::toInt (void) const
{
	// here help me
	return ((_value / (1 << _width)));
}

std::ostream&	operator << (std::ostream &os, const Fixed& f)
{
	os << (f.toFloat());
	return (os);
}
