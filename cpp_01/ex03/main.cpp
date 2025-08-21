#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		// std::cout << "before:" << std::endl << club.getType() << std::endl;
		club.setType("some other type of club");
		// std::cout << "after:" << std::endl << club.getType() << std::endl;
		jim.attack();
	}
	return 0;
}
