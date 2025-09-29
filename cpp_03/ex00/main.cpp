#include "ClapTrap.hpp"

int main(void)
{
	std::string oponnent = "Tesla";
	ClapTrap C("Newton");
	C.takeDamage(3);
	C.beRepaired(2);
	C.attack(oponnent);
}
