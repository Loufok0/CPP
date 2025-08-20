#include "Zombie.hpp"

int	main (int ac, char **av)
{
	int	N = 5;
	if (ac > 1)
	{
		std::istringstream n(av[1]);
		n >> N;
	}

	Zombie *z;
	z = zombieHorde(N, "Jonathan");

	for (int i = 0; i < N; i++)
		z[i].announce();

	delete [] z;
}
