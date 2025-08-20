#pragma once
#include <iostream>
#include <string>
#include <sstream>


class Weapon
{
	private:

		std::string	_type;

	public:

		std::string const&	getType(void);

		void	setType(std::string newType);
};
