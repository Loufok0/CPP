#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::string oponnent = "Tesla";
	std::string name = "Newton";
	FragTrap C(name);
	C.takeDamage(3);
	C.beRepaired(2);
	C.attack(oponnent);
	// std::cout << C.getHp() << std::endl;
}
