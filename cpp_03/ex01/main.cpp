#include "ScavTrap.hpp"

int main(void)
{
	std::string oponnent = "Tesla";
	std::string name = "Newton";
	ScavTrap C(name);
	C.takeDamage(3);
	C.beRepaired(2);
	C.attack(oponnent);
	// std::cout << C.getHp() << std::endl;
}
