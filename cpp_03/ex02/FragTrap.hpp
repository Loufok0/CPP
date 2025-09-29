#pragma once

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:

		FragTrap();
		FragTrap(const char *name);
		FragTrap(const ClapTrap &other);
		~FragTrap();
		void	attack(const std::string& target);
		void	beRepaired(unsigned int amount);
		void	takeDamage(unsigned int amount);

		void highFivesGuys(void) const;
};
