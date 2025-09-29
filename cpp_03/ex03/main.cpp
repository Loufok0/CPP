#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DaimondTrap.hpp"

int main(void)
{
	std::string oponnent = "Tesla";
	DaimondTrap C("Newton");
	C.takeDamage(3);
	C.beRepaired(2);
	C.attack(oponnent);
	C.highFivesGuys();
}
