#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	// std::cout << "Animal parameterized constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {}

Animal& Animal::operator = (const Animal &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const
{
	return (_type);
}

void Animal::makeSound(void) const
{
	std::cout << "Oh, I think this Animal is trying to comunicate" << std::endl;
}
