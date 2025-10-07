#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	_type = other._type;
	_brain = new Brain(*other.getBrain());
}

Dog& Dog::operator = (const Dog &other)
{
	if (this != &other)
	{
		delete _brain;
		_type = other._type;
		_brain = new Brain(*other.getBrain());
	}
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "[Dog] Woof Woof!" << std::endl;
}
