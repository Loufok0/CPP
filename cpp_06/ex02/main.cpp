#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "colors.hpp"

int main(void)
{
	Base *tmp;
	int i = -1;

	while (++i < 10)
	{
		std::cout << GREEN << "ITTERATION N " << RED << i << RESET << std::endl;

		tmp = generate();
		Base &tmp2 = *tmp;
		std::cout << "Pointer:" << std::endl;
		identify(tmp);
		std::cout << "Address:" << std::endl;
		identify(tmp2);
	
		std::cout << std::endl << std::endl;
	}

}
