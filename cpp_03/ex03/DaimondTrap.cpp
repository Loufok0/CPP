#include "DaimondTrap.hpp"


DaimondTrap::DaimondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _name("NoName")
{
	setHp(FragTrap::getHp());
	setEp(ScavTrap::getEp());
	setAtt(FragTrap::getAtt());
	std::cout << "Constructer called, DaimondTrap " << getName() << " built" << std::endl;
}

DaimondTrap::DaimondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), _name(name)
{
	setHp(FragTrap::getHp());
	setEp(ScavTrap::getEp());
	setAtt(FragTrap::getAtt());
	std::cout << "Constructer called, DaimondTrap " << getName() << " built" << std::endl;
}

DaimondTrap::DaimondTrap(const DaimondTrap &other) : ClapTrap::ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	setHp(FragTrap::getHp());
	setEp(ScavTrap::getEp());
	setAtt(FragTrap::getAtt());
	std::cout << "Constructer called, DaimondTrap " << getName() << " built" << std::endl;
}

DaimondTrap& DaimondTrap::operator = (const DaimondTrap &other)
{
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHp(other.getHp());
		this->setEp(other.getEp());
		this->setAtt(other.getAtt());
	}
	return (*this);
}

DaimondTrap::~DaimondTrap()
{
	std::cout << "Destructer called, DaimondTrap " << getName() << " annihilated" << std::endl;
}

void DaimondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}


void	DaimondTrap::beRepaired(unsigned int amount)
{
	if (getEp() <= 0)
		return ;
	std::cout << getName() << " repairs " << amount << " hit points" << std::endl;
	setEp(getEp() - 1);
	setHp(getHp() + amount);
}

void	DaimondTrap::takeDamage(unsigned int amount)
{
	std::cout << "DaimondTrap " << getName() << " has taken " << amount << " points of damage!" << std::endl;
	setHp(getHp() - amount);
}

void	DaimondTrap::whoAmI(void)
{
	 std::cout << "Hi, my name is " << getName() << " (ClapTrap name)" << " but you can call me " << _name << " (DaimondTrap name)" << std::endl << std::endl;
}
