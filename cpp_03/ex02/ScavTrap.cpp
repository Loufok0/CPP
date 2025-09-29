#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap::ClapTrap()
{
	setHp(100);
	setEp(50);
	setAtt(20);
	std::cout << "Constructer called, ScavTrap " << getName() << " built" << std::endl;
}

ScavTrap::ScavTrap(const char *name) : ClapTrap::ClapTrap(name)
{
	setHp(100);
	setEp(50);
	setAtt(20);
	std::cout << "Constructer called, ScavTrap " << getName() << " built" << std::endl;
}

ScavTrap::ScavTrap(const ClapTrap &other) : ClapTrap::ClapTrap(other)
{
	setHp(100);
	setEp(50);
	setAtt(20);
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

void ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode." << std::endl;
}
