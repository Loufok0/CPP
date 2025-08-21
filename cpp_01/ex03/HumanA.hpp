#pragma once
#include "Weapon.hpp"

class HumanA
{

	private:

		std::string	_name;
		Weapon		&_weapon;

	public:

		HumanA (const char *name, Weapon &weapon);
		~HumanA (void);
		void	attack(void) const;
		void	setWeapon(Weapon weapon);
};
