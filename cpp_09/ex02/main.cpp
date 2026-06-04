#include "./PmergeMe.hpp"

int	main(int ac, char **av)
{
	Core C;
	std::string raw;

	if (ac < 2)
	{
		std::cerr << ERROR << "Usage: " << av[0] << " <positive integer sequence>" << std::endl;
		return (1);
	}
	else if (ac > 2)
		raw = multiple_args(ac, av);
	else
		raw = std::string(av[1]);

	if (!parse(C, raw))
		return (1);

	process_vec(C.vec);
	process_deq(C.deq);
	// process_deq(C.deq);

	return (0);
}
