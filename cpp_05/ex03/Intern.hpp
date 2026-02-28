# pragma once

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include "colors.hpp"
#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern& operator = (const Intern &other);
		~Intern(void);

		AForm* makeForm(const std::string name, const std::string target);
};
