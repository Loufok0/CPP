#include "./PmergeMe.hpp"

int g_count = 0;


// ===========================PARSING============================


std::string multiple_args(int ac, char **av)
{
	std::string f;
	for (int i = 1; i < ac; i++)
		f += std::string(av[i]) + " ";
	return (f);
}

int parse(Core& C, std::string raw)
{
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
				std::cerr << ERROR << "Unexpected end of input... " << RESET << std::endl;
			else
			{
				std::cerr << ERROR << "Unknown char: " << YELLOW << raw[i] << RESET << std::endl;
				std::cerr << "Here: " << raw.substr(0, i) << YELLOW << raw[i] << RESET << raw.substr(i + 1) << std::endl;
			}
			return (0);
		}

		C.vec.push_back(sign * atoi(tmp.c_str()));
		C.deq.push_back(sign * atoi(tmp.c_str()));
	}
	return (1);
}


// ===========================PROCESS============================


void	process_vec(std::vector<int> vec)
{
	g_count = 0;
	clock_t start = clock();

	std::cout << DEBUG << "VEC HERE:" << std::endl;
	std::cout << "Before:" << std::endl;
	std::vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;

	std::vector<int> res = FJ(vec);

	std::cout << std::endl << "After:" << std::endl;
	for (it = res.begin(); it != res.end(); it++)
		std::cout << *it << std::endl;

	clock_t end = clock();
	double ms = 1000.0 * (double)(end - start) / CLOCKS_PER_SEC;

	std::cout << "Comparaisons count: " << g_count << " comparaisons" << std::endl;
	std::cout << "Time: " << ms << " ms elipsed" << std::endl << std::endl;
}

void	process_deq(std::deque<int> deq)
{
	g_count = 0;
	clock_t start = clock();

	std::cout << DEBUG << "DEQ HERE:" << std::endl;
	std::cout << "Before:" << std::endl;
	std::deque<int>::iterator it;
	for (it = deq.begin(); it != deq.end(); it++)
		std::cout << *it << std::endl;

	std::deque<int> res = FJ(deq);

	std::cout << std::endl << "After:" << std::endl;
	for (it = res.begin(); it != res.end(); it++)
		std::cout << *it << std::endl;

	clock_t end = clock();
	double ms = 1000.0 * (double)(end - start) / CLOCKS_PER_SEC;

	std::cout << "Comparaisons count: " << g_count << " comparaisons" << std::endl;
	std::cout << "Time: " << ms << " ms elipsed" << std::endl << std::endl;
}



// ===========================JACOBSTHAL============================


int Jacobsthal(int n)
{
	// base case
	if (n == 0)
		return 0;

	// base case
	if (n == 1)
		return 1;

	// recursive step.
	return (Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2));
}


// ===========================FORDJHONSON============================


std::vector<int> FJ(std::vector<int> vec)
{
	if (vec.size() <= 1)
		return (vec);

	std::vector<s_pairs> pairs;

	int odd = -1;
	if (vec.size() % 2 != 0)
		odd = vec[vec.size() - 1];

	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		s_pairs tmp;
		tmp.big = biggest(vec[i], vec[i + 1]);
		if (tmp.big == vec[i])
			tmp.small = vec[i + 1];
		else
			tmp.small = vec[i];
		pairs.push_back(tmp);
	}

	std::vector<int> bigs;
	for (size_t i = 0; i < pairs.size(); i++)
		bigs.push_back(pairs[i].big);

	std::vector<int> smalls;
	for (size_t i = 0; i < pairs.size(); i++)
		smalls.push_back(pairs[i].small);

	std::vector<int> sorted = FJ(bigs);

	std::vector<int>::iterator bigPos = find(sorted.begin(), sorted.end(), pairs[0].big);
	std::vector<int>::iterator pos = lower_bound(sorted.begin(), bigPos + 1, smalls[0] , a_inf_to_b);
	sorted.insert(pos, smalls[0]); // smalls[0] < his bigs[x];

	int curr = Jacobsthal(2);
	int prev = 0;
	int j = 2;
	while (prev < (int)smalls.size())
	{
		for (int i = (int)std::min((int)smalls.size() - 1, curr); i > prev; i--)
		{
			std::vector<int>::iterator bigPos = find(sorted.begin(), sorted.end(), pairs[i].big);
			std::vector<int>::iterator pos = lower_bound(sorted.begin(), bigPos + 1, smalls[i], a_inf_to_b);
			sorted.insert(pos, smalls[i]);
		}
		prev = curr;
		j++;
		curr = Jacobsthal(j);
	}
	if (odd != -1)
	{
		std::vector<int>::iterator pos = lower_bound(sorted.begin(), sorted.end(), odd, a_inf_to_b);
		sorted.insert(pos, odd);
	}
	if (sorted.size() != vec.size()) {
    std::cerr << "ERROR: Input size " << vec.size() 
              << " != Output size " << sorted.size() << std::endl;
	}
	return (sorted);

}

std::deque<int> FJ(std::deque<int> deq)
{
	if (deq.size() <= 1)
		return (deq);

	std::deque<s_pairs> pairs;

	int odd = -1;
	if (deq.size() % 2 != 0)
		odd = deq[deq.size() - 1];

	for (size_t i = 0; i + 1 < deq.size(); i += 2)
	{
		s_pairs tmp;
		tmp.big = biggest(deq[i], deq[i + 1]);
		if (tmp.big == deq[i])
			tmp.small = deq[i + 1];
		else
			tmp.small = deq[i];
		pairs.push_back(tmp);
	}

	std::deque<int> bigs;
	for (size_t i = 0; i < pairs.size(); i++)
		bigs.push_back(pairs[i].big);

	std::deque<int> smalls;
	for (size_t i = 0; i < pairs.size(); i++)
		smalls.push_back(pairs[i].small);

	std::deque<int> sorted = FJ(bigs);

	std::deque<int>::iterator bigPos = find(sorted.begin(), sorted.end(), pairs[0].big);
	std::deque<int>::iterator pos = lower_bound(sorted.begin(), bigPos + 1, smalls[0], a_inf_to_b);
	sorted.insert(pos, smalls[0]); // smalls[0] < his bigs[x];

	int curr = Jacobsthal(2);
	int prev = 0;
	int j = 2;
	while (prev < (int)smalls.size())
	{
		for (int i = (int)std::min((int)smalls.size() - 1, curr); i > prev; i--)
		{
			std::deque<int>::iterator bigPos = find(sorted.begin(), sorted.end(), pairs[i].big);
			std::deque<int>::iterator pos = lower_bound(sorted.begin(), bigPos + 1, smalls[i], a_inf_to_b);
			sorted.insert(pos, smalls[i]);
		}
		prev = curr;
		j++;
		curr = Jacobsthal(j);
	}
	if (odd != -1)
	{
		std::deque<int>::iterator pos = lower_bound(sorted.begin(), sorted.end(), odd, a_inf_to_b);
		sorted.insert(pos, odd);
	}
	if (sorted.size() != deq.size()) {
    std::cerr << "ERROR: Input size " << deq.size() 
              << " != Output size " << sorted.size() << std::endl;
	}
	return (sorted);

}



// ===========================UTILS============================


bool a_inf_to_b (int a, int b)
{
	g_count++;
	return (a < b);
}

bool a_sup_to_b (int a, int b)
{
	g_count++;
	return (a > b);
}

int biggest (int a, int b)
{
	g_count++;
	if (a > b)
		return (a);
	return (b);
}
