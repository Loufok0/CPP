#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Weapon
{
	private:

		std::string	_type;

	public:

		Weapon(const std::string type = "his bares hands...");
		~Weapon(void);
		Weapon(const Weapon& another);

		const std::string&	getType(void) const;
		void	setType(const std::string newType);
};
