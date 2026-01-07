#include "iter.hpp"

template <typename T>
void f(T* a)
{
	(*a)++;
}

template <typename T>
void g(const T* a)
{
	std::cout << (*a) << "? That's a const bro, what did you want me to do with..." << std::endl;
}

template <typename T>
void show_arr(T* arr, int size)
{
	int i = 0;
	while (i < size)
		std::cout << arr[i++] << " ";
	std::cout << std::endl;
}

int	main(void)
{
	{
		std::cout << BLUE << "Int array:" << RESET << std::endl;
		int ia[] = {1, 8, 3, 7, 0};
		int size = sizeof(ia) / sizeof(ia[0]);
		show_arr(ia, size);
		iter(ia, size, f);
		size = sizeof(ia) / sizeof(ia[0]);
		show_arr(ia, size);
		std::cout << std::endl << std::endl;
	}
	{
		std::cout << BLUE << "Char array:" << RESET << std::endl;
		char ia[] = {'r', 'r', 'e', 'y'};
		char size = sizeof(ia) / sizeof(ia[0]);
		show_arr(ia, size);
		iter(ia, size, f);
		size = sizeof(ia) / sizeof(ia[0]);
		show_arr(ia, size);
		std::cout << std::endl << std::endl;
	}

	{
		std::cout << BLUE << "Const char array:" << RESET << std::endl;
		const char ia[] = {'a', 'b', 'c', 'd'};
		char size = sizeof(ia) / sizeof(ia[0]);
		show_arr(ia, size);
		iter(ia, size, g);
		size = sizeof(ia) / sizeof(ia[0]);
		show_arr(ia, size);
		std::cout << std::endl << std::endl;
	}
}
