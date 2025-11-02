#pragma once

#include <iostream>
#include "Brain.hpp"

class Animal
{
	protected:

		std::string	_type;
		Brain		*_brain;

	public:


		Animal();
		Animal(std::string type);
		Animal(const Animal &other);
		Animal& operator = (const Animal &other);
		virtual ~Animal() = 0;

		virtual void makeSound(void) const;
		std::string getType(void) const;
		virtual Brain* getBrain(void) const;
		virtual void	thoughts(void)	const;
};
