#pragma once

#include "Animal.hpp"

class Cat : virtual private Animal
{
	private:

		Brain* _brain;

	public:

		Cat();
		Cat(const Cat &other);
		Cat& operator = (const Cat &other);
		~Cat();

		void makeSound(void) const;

};
