#include <iostream>
#include "Point.hpp"

int main( void ) {

	Point a(0, 3);
	Point b(3, 1);
	Point c(4, 4);
	
	Point p(2, 3.5); // ici p appartient a [ab] et [pa] = [pb]

	bool inTriangle = bsp(a, b, c, p);
	std::cout << "is " << p << " in the triangle abc with: " << std::endl;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	if (inTriangle)
		std::cout << "Answer: True" << std::endl;
	else
		std::cout << "Answer: False" << std::endl;

return 0;
}

