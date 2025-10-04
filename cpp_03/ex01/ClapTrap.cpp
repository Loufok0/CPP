#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : _name("NoName"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "Constructer called, ClapTrap " << _name << " built" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "Constructer called, ClapTrap " << _name << " built" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "Constructer called, ClapTrap" << _name << " built" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoint = other._hitPoint;
		_energyPoint = other._energyPoint;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << std::endl << std::endl << "Destructer called, ClapTrap " << _name << " annihilated" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoint <= 0)
		return ;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoint--;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoint <= 0)
		return ;
	std::cout << _name << " repairs " << amount << " hit points" << std::endl;
	_energyPoint--;
	_hitPoint += amount;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " has taken " << amount << " points of damage!" << std::endl;
	_hitPoint -= amount;
}


void ClapTrap::setName(const std::string n)
{
	this->_name = n;
}

const std::string ClapTrap::getName() const
{
	return (_name);
}

void ClapTrap::setEp(const int n)
{
	this->_energyPoint = n;
}

int ClapTrap::getEp() const
{
	return (_energyPoint);
}

void ClapTrap::setHp(const int n)
{
	this->_hitPoint = n;
}

int ClapTrap::getHp(void) const
{
	return (_hitPoint);
}

void ClapTrap::setAtt(const int n)
{
	this->_attackDamage = n;
}

int ClapTrap::getAtt() const
{
	return (_attackDamage);
}
