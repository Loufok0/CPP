#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap::ClapTrap()
{
	std::cout << "Constructer called, ScavTrap " << getName() << " built" << std::endl;
}

ScavTrap::ScavTrap(const char *name) : ClapTrap::ClapTrap(name)
{
	std::cout << "Constructer called, ScavTrap " << getName() << " built" << std::endl;
}

ScavTrap::ScavTrap(const ClapTrap &other) : ClapTrap::ClapTrap(other)
{
	std::cout << "Constructer called, ScavTrap " << getName() << " built" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << std::endl << std::endl << "Destructer called, ScavTrap " << getName() << " annihilated" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (getEp() <= 0)
		return ;
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAtt() << " points of damage!" << std::endl;
	setEp(getEp() - 1);
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (getEp() <= 0)
		return ;
	std::cout << getName() << " repairs " << amount << " hit points" << std::endl;
	setEp(getEp() - 1);
	setHp(getHp() + amount);
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap " << getName() << " has taken " << amount << " points of damage!" << std::endl;
	setHp(getHp() - amount);
}
