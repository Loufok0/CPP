#include "Weapon.hpp"


std::string const&	Weapon::getType(void)
{
	return (_type);
}

void	Weapon::setType(std::string newType)
{
	_type = newType;
}
