#include "DaimondTrap.hpp"


DaimondTrap::DaimondTrap() : ClapTrap::ClapTrap()
{
	setHp(100);
	setEp(50);
	setAtt(20);
	std::cout << "Constructer called, DaimondTrap " << getName() << " built" << std::endl;
}

DaimondTrap::DaimondTrap(const char *name) : ClapTrap::ClapTrap(name)
{
	setHp(100);
	setEp(50);
	setAtt(20);
	std::cout << "Constructer called, DaimondTrap " << getName() << " built" << std::endl;
}

DaimondTrap::DaimondTrap(const ClapTrap &other) : ClapTrap::ClapTrap(other)
{
	setHp(100);
	setEp(50);
	setAtt(20);
	std::cout << "Constructer called, DaimondTrap " << getName() << " built" << std::endl;
}

DaimondTrap::~DaimondTrap()
{
	std::cout << std::endl << std::endl << "Destructer called, DaimondTrap " << getName() << " annihilated" << std::endl;
}

void	DaimondTrap::attack(const std::string& target)
{
	if (getEp() <= 0)
		return ;
	std::cout << "DaimondTrap " << getName() << " attacks " << target << ", causing " << getAtt() << " points of damage!" << std::endl;
	setEp(getEp() - 1);
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

void DaimondTrap::guardGate(void) const
{
	std::cout << "DaimondTrap " << getName() << " is now in Gate keeper mode." << std::endl;
}

void DaimondTrap::highFivesGuys(void) const
{
	const char* phrases[] = {
	"Secret handshake!",
	"Up top!",
	"Gimme five!",
	"High five!",
	"Up top!"
	};

	int nb_phrases = sizeof(phrases) / sizeof(phrases[0]);

	std::srand(std::time(0));
	int index = std::rand() % nb_phrases;

	std::cout << "DaimondTrap request a high fives: \"" << phrases[index] << "\"" << std::endl << std::endl << std::endl ;
}
