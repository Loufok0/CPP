#include "Zombie.hpp"


Zombie::Zombie(void) {}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << _name << " finnaly died !"<< std::endl;
}


std::string	Zombie::getName (void)
{
	return (_name);
}

void	Zombie::setName (std::string name)
{
	_name = name;
}

void		Zombie::announce (void)
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
