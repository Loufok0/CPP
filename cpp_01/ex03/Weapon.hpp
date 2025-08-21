#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Weapon
{
	private:

		std::string	_type;

	public:

		Weapon(std::string type);
		~Weapon(void);
Weapon(const Weapon& another);

		std::string const&	getType(void) const;
		void	setType(std::string newType);
};
