#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Weapon
{
	private:

		std::string	_type;

	public:

		Weapon(const char *type);
		~Weapon(void);
		Weapon(const Weapon& another);

		const std::string&	getType(void) const;
		void	setType(const char *newType);
};
