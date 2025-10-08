#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:

		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap(const ClapTrap &other);
		ScavTrap& operator = (const ScavTrap &other);
		~ScavTrap();

		void	attack(const std::string& target);
		void	beRepaired(unsigned int amount);
		void	takeDamage(unsigned int amount);

		void	guardGate(void) const;
};
