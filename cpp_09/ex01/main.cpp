#include "./RPN.hpp"

int main(int ac, char**av)
{
	if (ac != 2)
	{
		std::cout << ERROR << "Usage: " << av[0] << " <Reverse Polish Notation Calcul>" << std::endl;
		return (1);
	}
	RPN R(av[1]);
	R.eval();
}
