#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:

		ScavTrap();
		ScavTrap(const char *name);
		ScavTrap(const ClapTrap &other);
		~ScavTrap();
		void	attack(const std::string& target);
		void	beRepaired(unsigned int amount);
		void	takeDamage(unsigned int amount);

};
