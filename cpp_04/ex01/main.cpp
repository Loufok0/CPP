#include "Cat.hpp"
#include "Dog.hpp"

int main (void)
{
	const Animal* arr[20];
	for (int i = 0;i < 20;i++)
	{
		if (i < 10)
			arr[i] = new Cat();
		else
			arr[i] = new Dog();
	}


	for (int i = 0;i < 20;i++)
		std::cout << "animal[" << i << "]'s type: " << arr[i]->getType() << std::endl;
	std::cout << std::endl << std::endl;

	for (int i = 0;i < 20;i++)
		arr[i]->makeSound();
	std::cout << std::endl << std::endl;

	arr[0]->thoughts();
	arr[15]->thoughts();
	std::cout << std::endl << std::endl;

	for (int i = 0;i < 20;i++)
		delete arr[i];
	std::cout << std::endl << std::endl;



	const Cat cat1;
	Cat cat2 = cat1;
	
	std::cout << "Address of cat1's brain: " << cat1.getBrain() << std::endl;
	std::cout << "Address of cat2's brain: " << cat2.getBrain() << std::endl;
	
	cat1.getBrain()->thoughts();
	cat2.getBrain()->thoughts();

	if (cat1.getBrain() != cat2.getBrain())
	    std::cout << "Deep copy ✅" << std::endl;
	else
	    std::cout << "Shallow copy ❌" << std::endl;
	

	return (0);
}
