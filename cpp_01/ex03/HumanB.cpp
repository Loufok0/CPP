#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB(void) {}

void	HumanB::attack(void) const
{
	if (_weapon != NULL)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with their bares hands" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
