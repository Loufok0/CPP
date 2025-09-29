#pragma once

#include "ClapTrap.hpp"

class DaimondTrap: public ClapTrap
{
	public:

		DaimondTrap();
		DaimondTrap(const char *name);
		DaimondTrap(const ClapTrap &other);
		~DaimondTrap();
		void	attack(const std::string& target);
		void	beRepaired(unsigned int amount);
		void	takeDamage(unsigned int amount);

		void guardGate(void) const;
		void highFivesGuys(void) const;
};
