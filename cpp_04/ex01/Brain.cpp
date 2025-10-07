#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	_ideas = new other._ideas;
}

Brain& Brain::operator = (const Brain &other)
{
	if (this != &other)
		_ideas = other._ideas;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
