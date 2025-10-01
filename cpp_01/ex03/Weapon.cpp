#include "Weapon.hpp"

Weapon::Weapon(const std::string type)
{
	_type = type;
}

Weapon::~Weapon(void) {}

Weapon::Weapon(const Weapon& another)
{
	this->_type = another._type;
}

std::string const&	Weapon::getType(void) const
{
	return (_type);
}

void	Weapon::setType(const std::string newType)
{
	_type = newType;
}
