#include "./btc.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << ERROR << "Usage: " << av[0] << " input.txt" << std::endl;
		return (1);
	}

	std::ifstream	input(av[1]);
	if (!input)
	{
		std::cout << ERROR << "Couldn't open input file named" << av[1] << std::endl;
		return (1);
	}
	std::ifstream	data("./data.csv");
	if (!data)
	{
		std::cout << ERROR << "Couldn't open data file ./data.csv" << std::endl;
		return (1);
	}
	Btc B;
	B.printInput();
	B.printData();

}
