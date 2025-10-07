#pragma once

#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
	public:

		WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat& operator = (const WrongCat &other);
		~WrongCat();

};
