#pragma once
#include <iostream>
#include <string>
#include <sstream>

class	 Zombie
{
	private:
		std::string		_name;

	public:

		Zombie(void);
		~Zombie(void);

		void			announce (void);
		std::string		getName (void);
		void			setName (std::string);

};

Zombie* zombieHorde(int N, std::string name);
