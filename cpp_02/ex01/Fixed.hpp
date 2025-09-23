#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_width = 8;

	public:

		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		int		getRawBits (void) const;
		void	setRawBits (int const raw);

		float toFloat (void) const;
		int toInt (void) const;
		Fixed &operator<<(std::ostream &os);


And add the following function to the Fixed class files:

An overload of the insertion («) operator that inserts a floating-point representation
of the fixed-point number into the output stream object passed as a parameter.

};
