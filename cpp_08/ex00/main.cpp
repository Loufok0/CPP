#include "./easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	{
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
	
		try
		{
			std::vector<int>::iterator it = easyfind(v, 2);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::list<int> l;
		l.push_back(10);
		l.push_back(20);
	
		try
		{
			std::list<int>::iterator it = easyfind(l, 42);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::deque<int> l;
		l.push_back(10);
		l.push_back(20);
		l.push_back(20);
		l.push_back(20);
		l.push_back(20);
		l.push_back(20);
		l.push_back(42);
	
		try
		{
			std::deque<int>::iterator it = easyfind(l, 42);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
