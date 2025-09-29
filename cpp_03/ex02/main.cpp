#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::string oponnent = "Tesla";
	FragTrap C("Newton");
	C.takeDamage(3);
	C.beRepaired(2);
	C.attack(oponnent);
	C.highFivesGuys();
}
