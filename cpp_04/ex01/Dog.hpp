#pragma once

#include "Animal.hpp"

class Dog : virtual private Animal
{
	private:

		Brain* _brain;

	public:

		Dog();
		Dog(const Dog &other);
		Dog& operator = (const Dog &other);
		~Dog();

		void makeSound(void) const;
};
