#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main (void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl << std::endl;
	std::cout << "j's type: " << j->getType() << " " << std::endl;
	std::cout << "i's type: " << i->getType() << " " << std::endl;

	std::cout << std::endl << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();

	std::cout << std::endl << std::endl;
	delete i;
	delete j;
	delete meta;






	std::cout << std::endl << std::endl;
	const WrongAnimal* wA = new WrongAnimal();
	const WrongAnimal* wC = new WrongCat();

	std::cout << std::endl << std::endl;
	std::cout << "wA's type: " << wA->getType() << " " << std::endl;
	std::cout << "wC's type: " << wC->getType() << " " << std::endl;

	std::cout << std::endl << std::endl;
	wA->makeSound();
	wC->makeSound(); //will output the wrong cat sound!

	std::cout << std::endl << std::endl;
	delete wA;
	delete wC;


	return 0;
}
