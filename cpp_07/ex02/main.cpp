#include "./Array.hpp"

int main (void)
{
//=============================[INT]=================================//
	int i = 0;
	{
		std::cout << BLUE << "INT" << RESET << std::endl;
		Array<int> a;

		try
		{
			i = 0;
			while (i < 20)
			std::cout << a[i++] << std::endl;
		}
		catch (const Array<int>::OutOfBound& e)
		{
			std::cout << "Error catched: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
	
//=============================[FLOAT]=================================//

	{
		std::cout << BLUE << "FLOAT" << RESET << std::endl;
		Array<float> b(10);
		Array<float> c = b;

		try
		{
			i = 0;
			while (i < 20)
			std::cout << c[i++] << std::endl;
		}
		catch (const Array<float>::OutOfBound& e)
		{
			std::cout << "Error catched: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;

//=============================[CHAR]=================================//

	{
		std::cout << BLUE << "CHAR" << RESET << std::endl;
		Array<char> d(10);

		try
		{
			i = 0;
			std::cout << "value of the char:" << std::endl;
			while (i < 20)
				std::cout << (char)(d[i++] + '0') << std::endl;
		}
		catch (const Array<char>::OutOfBound& e)
		{
			std::cout << "Error catched: " << e.what() << std::endl;
		}

		i = -1;
		while (++i < d.size())
			d[i] = 'a' + i;

		try
		{
			i = 0;
			while (i < 20)
			std::cout << d[i++] << std::endl;
		}
		catch (const Array<char>::OutOfBound& e)
		{
			std::cout << "Error catched: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;

//=============================[STRING]=================================//

	{
		std::cout << BLUE << "CHAR" << RESET << std::endl;
		Array<std::string> f(10);

		try
		{
			i = 0;
			std::cout << "value of the char:" << std::endl;
			while (i < 20)
				std::cout << f[i++] << std::endl;
		}
		catch (const Array<std::string>::OutOfBound& e)
		{
			std::cout << "Error catched: " << e.what() << std::endl;
		}

		i = -1;
		while (++i < f.size())
			f[i] = 'a' + i;

		try
		{
			i = 0;
			while (i < 20)
			std::cout << f[i++] << std::endl;
		}
		catch (const Array<std::string>::OutOfBound& e)
		{
			std::cout << "Error catched: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
}
