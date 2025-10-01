#pragma once
#include "Weapon.hpp"

class HumanA
{

	private:

		std::string	_name;
		Weapon		&_weapon;

	public:

		HumanA (const std::string name, Weapon &weapon);
		~HumanA (void);
		void	attack(void) const;
		void	setWeapon(Weapon weapon);
};
