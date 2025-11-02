#pragma once

#include "Animal.hpp"

class Cat : virtual public Animal
{
	private:

		Brain* _brain;

	public:

		Cat();
		Cat(const Cat &other);
		Cat& operator = (const Cat &other);
		~Cat();

		Brain* getBrain(void) const;
		void makeSound(void) const;
		void	thoughts(void)	const;
};
