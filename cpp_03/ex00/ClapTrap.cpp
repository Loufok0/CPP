#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : _name("NoName"), _hitPoint(10), _energyPoint(10), _attackDamage(10)
{
	std::cout << "Constructer called, ClapTrap " << _name << " firsts words:" << std::endl;
	randQuote('c');
}

ClapTrap::ClapTrap(const char *name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(10)
{
	std::cout << "Constructer called, ClapTrap " << _name << " firsts words:" << std::endl;
	randQuote('c');
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoint(10), _energyPoint(10), _attackDamage(10)
{
	std::cout << "Constructer called, ClapTrap" << _name << "firsts words:" << std::endl;
	randQuote('c');
}

ClapTrap& ClapTrap::operator = (const ClapTrap &other)
{
	_name = other._name;
	_hitPoint = 10;
	_energyPoint = 10;
	_attackDamage = 10;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << std::endl << std::endl << "Destructer called, ClapTrap " << _name << " lasts words:" << std::endl;
	randQuote('d');
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



void	randQuote(const char c)
{
	const char* constructer[] = {
		"You want me? To join you? I am SO excited. We will be best friends.",
		"My programmer always said two hands are better then one. But then he only gave me one. I wonder why?",
		"I wanna come, can I come? I promise I won't get in the way. Please?",
		"Battlebot go -- Oh that's me",
		"Did somebody call the Lovebot? No, oh well I'm here anyways"
	};

	const char* destructer[] = {
		"I'll stop talking when I'm dead!",
		"I'll die the way I lived: annoying!",
		"This could've gone better!",
		"Yo momma's so dumb, she couldn't think of a good ending for this 'yo momma' joke!",
		"You're one screw short of a screw!",
		"I bet your mom could do better!",
		"Oh yeah? Well, uh... yeah.",
		"I'm leaking!",
		"Good thing I don't have a soul!",
		"Aww! Come on!",
		"You can't kill me!",
		"I'm too pretty to die!",
		"Crap!",
		"Robot down!",
		"No, nononono NO!",
		"I'll never go back to the bad place!",
		"I have many regrets!"
	};

	int nb_phrases = sizeof(constructer) / sizeof(constructer[0]);
	if (c == 'd')
		nb_phrases = sizeof(destructer) / sizeof(destructer[0]);

	std::srand(std::time(0));
	int index = std::rand() % nb_phrases;

	if (c == 'd')
	{
		std::cout << destructer[index] << std::endl;
	}
	else
	{
		std::cout << constructer[index] << std::endl << std::endl << std::endl ;
	}
}
