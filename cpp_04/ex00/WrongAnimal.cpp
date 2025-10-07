#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("No, you did it Wrong(Animal)")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	// std::cout << "WrongAnimal parameterized constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (_type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Oh, I think this WrongAnimal is trying to comunicate" << std::endl;
}
