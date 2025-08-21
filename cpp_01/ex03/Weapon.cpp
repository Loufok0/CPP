#include "Weapon.hpp"

Weapon::Weapon(const char *type)
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

void	Weapon::setType(const char *newType)
{
	_type = newType;
}
