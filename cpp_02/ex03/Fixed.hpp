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

		bool	operator > (const Fixed& f2) const;
		bool	operator < (const Fixed& f2) const;
		bool	operator >= (const Fixed& f2) const;
		bool	operator <= (const Fixed& f2) const;
		bool	operator == (const Fixed& f2) const;
		bool	operator != (const Fixed& f2) const;
		Fixed	operator ++ (int);
		Fixed	operator -- (int);
		Fixed&	operator ++ (void);
		Fixed&	operator -- (void);
		static Fixed	min (Fixed &f1, Fixed &f2);
		static Fixed	min (const Fixed &f1, const Fixed &f2);
		static Fixed	max (Fixed &f1, Fixed &f2);
		static Fixed	max (const Fixed &f1, const Fixed &f2);
		float	operator + (const Fixed& f2) const;
		float	operator - (const Fixed& f2) const;
		float	operator * (const Fixed& f2) const;
		float	operator / (const Fixed& f2) const;
};


	std::ostream& operator<<(std::ostream &os, const Fixed& f);
