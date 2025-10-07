#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	_type = other._type;
	_brain = new Brain(*other.getBrain());
}

Cat& Cat::operator = (const Cat &other)
{
	if (this != &other)
	{
		delete _brain;
		_type = other._type;
		_brain = new Brain(*other.getBrain());
	}
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "[Cat] Meow Meow!" << std::endl;
}
