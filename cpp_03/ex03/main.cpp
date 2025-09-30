#include "DaimondTrap.hpp"

int main(void)
{
	std::string oponnent = "Tesla";
	std::string name = "Gus";
	DaimondTrap C(name);
	std::cout << std::endl;
	C.takeDamage(3);
	C.beRepaired(2);
	C.attack(oponnent);
	C.highFivesGuys();
	C.guardGate();
	C.whoAmI();
}
