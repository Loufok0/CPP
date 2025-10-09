#pragma once

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:

		FragTrap();
		FragTrap(const std::string name);
		FragTrap(const ClapTrap &other);
		FragTrap& operator = (const FragTrap &other);
		~FragTrap();

		void	attack(const std::string& target);
		// void	beRepaired(unsigned int amount);
		// void	takeDamage(unsigned int amount);

		void highFivesGuys(void) const;
};
