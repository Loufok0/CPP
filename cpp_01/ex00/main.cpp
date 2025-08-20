#include "Zombie.hpp"

int	main (void)
{

Zombie z1("Dimitri");
Zombie *z2 = newZombie("Dimitri junior");
z1.announce();
z2->announce();
randomChump("Sarah");
delete z2;
}
