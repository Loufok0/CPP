#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {}

Cat& Cat::operator = (const Cat &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "[Cat] Meow Meow!" << std::endl;
}
