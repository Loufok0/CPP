#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DaimondTrap : public ScavTrap, public FragTrap
{
	private:

		const std::string _name;

	public:

		DaimondTrap();
		DaimondTrap(const std::string name);
		DaimondTrap(const DaimondTrap &other);
		DaimondTrap& operator = (const DaimondTrap &other);
		~DaimondTrap();
		void	attack(const std::string& target);
		void	beRepaired(unsigned int amount);
		void	takeDamage(unsigned int amount);

		void	whoAmI(void);
};
