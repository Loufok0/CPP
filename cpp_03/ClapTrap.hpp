#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

class ClapTrap
{
	private:

		const char *_name;
		int _hitPoint;
		int _energyPoint;
		int _attackDamage;

	public:

		ClapTrap();
		ClapTrap(const char *name);
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator = (const ClapTrap &other);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);


};

void	randQuote(const char c);
