#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap::ClapTrap()
{
	setHp(100);
	setEp(100);
	setAtt(30);
	std::cout << "Constructer called, FragTrap " << getName() << " built" << std::endl;
}

FragTrap::FragTrap(const char *name) : ClapTrap::ClapTrap(name)
{
	setHp(100);
	setEp(100);
	setAtt(30);
	std::cout << "Constructer called, FragTrap " << getName() << " built" << std::endl;
}

FragTrap::FragTrap(const ClapTrap &other) : ClapTrap::ClapTrap(other)
{
	setHp(100);
	setEp(100);
	setAtt(30);
	std::cout << "Constructer called, FragTrap " << getName() << " built" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << std::endl << std::endl << "Destructer called, FragTrap " << getName() << " annihilated" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (getEp() <= 0)
		return ;
	std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAtt() << " points of damage!" << std::endl;
	setEp(getEp() - 1);
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (getEp() <= 0)
		return ;
	std::cout << getName() << " repairs " << amount << " hit points" << std::endl;
	setEp(getEp() - 1);
	setHp(getHp() + amount);
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap " << getName() << " has taken " << amount << " points of damage!" << std::endl;
	setHp(getHp() - amount);
}

void FragTrap::highFivesGuys(void) const
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

	std::cout << "FragTrap request a high fives: \"" << phrases[index] << "\"" << std::endl << std::endl << std::endl ;
}
