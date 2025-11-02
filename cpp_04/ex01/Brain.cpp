#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const std::string *ideas)
{
	std::cout << "Brain parameterised constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = ideas[i];
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
}

Brain& Brain::operator = (const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdeas(const std::string *ideas)
{
	for (int i = 0;i < 100;i++)
		_ideas[i] = ideas[i];
}

void	Brain::thoughts(void)	const
{
	for (int i = 0; i < 100;i++)
		std::cout << _ideas[i] << std::endl;
	std::cout << std::endl;
}
