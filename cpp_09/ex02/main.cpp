#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <deque>
#include <vector>
#include "./colors.hpp"



std::vector<int> parse_vec(std::string raw)
{
	std::vector<int> vec;
	std::string tmp;
	int sign = 1;

	for (size_t i = 0; i < raw.size();)
	{
		tmp.clear();
		while (i < raw.size() && isspace(raw[i]))
			i++;
		if (i >= raw.size())
			break;

		if (i < raw.size() && (raw[i] == '+' || raw[i] == '-'))
		{
			sign *= (44 - raw[i]);
			i++;
		}
		while (i < raw.size() && isdigit(raw[i]))
		{
			tmp += raw[i];
			i++;
		}
		if (tmp.empty())
		{
			if (i >= raw.size())
			{
				std::cerr << ERROR << "Unexpected end of input... " << RESET << std::endl;
			}
			else
			{
				std::cerr << ERROR << "Unknown char: " << YELLOW << raw[i] << RESET << std::endl;
				std::cerr << "Here: " << raw.substr(0, i) << YELLOW << raw[i] << RESET << raw.substr(i + 1) << std::endl;
			}
			vec.push_back(-1);
			vec[0] = -1;
			return (vec);
		}

		vec.push_back(sign * atoi(tmp.c_str()));
	}
	return (vec);
}

void	process_vec(std::vector<int> vec)
{
	if (vec[0] < 0)
		return;
	std::vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
}

std::string multiple_args(int ac, char **av)
{
	std::string f;
	for (int i = 1; i < ac; i++)
		f += std::string(av[i]) + " ";
	return (f);
}

int	main(int ac, char **av)
{
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

	process_vec(parse_vec(raw));
	return (0);
}
