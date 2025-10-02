#include "Harl.hpp"


int	main (int ac, char **av)
{
	Harl h;

	if (ac != 2)
	{
		std::cout << "Usage: ./HARL <Warning level>" << std::endl;
		return (1);
	}

	int i = 0;
	std::string names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < NBLEVEL)
	{
		if ((static_cast<std::string>(av[1])).compare(names[i]) == 0)
			break ;
		i++;
	}
	if (i == NBLEVEL)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}

	switch (i)
	{
		case 0:
			h.complain("DEBUG");
			h.complain("INFO");
			h.complain("WARNING");
			h.complain("ERROR");
			break ;

		case 1:
			h.complain("INFO");
			h.complain("WARNING");
			h.complain("ERROR");
			break ;

		case 2:
			h.complain("WARNING");
			h.complain("ERROR");
			break ;

		case 3:
			h.complain("ERROR");
			break ;

	}
	return (0);
}
