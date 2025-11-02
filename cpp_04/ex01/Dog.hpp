#pragma once

#include "Animal.hpp"

class Dog : virtual public Animal
{
	private:

		Brain* _brain;

	public:

		Dog();
		Dog(const Dog &other);
		Dog& operator = (const Dog &other);
		~Dog();

		Brain* getBrain(void) const;
		void makeSound(void) const;
		void	thoughts(void)	const;
};
