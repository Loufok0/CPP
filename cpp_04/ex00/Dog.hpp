#pragma once

#include "Animal.hpp"

class Dog : virtual public Animal
{
	public:

		Dog();
		Dog(const Dog &other);
		Dog& operator = (const Dog &other);
		~Dog();

		void makeSound(void) const;
};
