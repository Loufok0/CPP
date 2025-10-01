#pragma once
#include "Weapon.hpp"

class HumanB
{

	private:

		std::string _name;
		Weapon		*_weapon;

	public:

		HumanB (const std::string name);
		~HumanB (void);
		void	attack(void) const;
		void	setWeapon(Weapon &weapon);
};
