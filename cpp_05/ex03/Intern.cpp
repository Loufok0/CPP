#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}
Intern::Intern(const Intern &other) {(void)other;}
Intern& Intern::operator = (const Intern &other) {(void)other; return (*this);}
Intern::~Intern(void) {}

AForm* createShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* createRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* createPresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{
	AForm* (*f[3])(const std::string&) = {createShrubbery, createRobotomy, createPresidential};
	std::string n[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 0;

	while (i < 3)
	{
		if (name == n[i])
		{
			std::cout << "Intern creates " << GREEN << name << RESET << std::endl;
			return (f[i](target));
		}
		i++;
	}
	std::cout << "Intern coulnd't create " << RED << name << RESET << " because it is not an official form..." << std::endl;
	return (NULL);
}


/*
AForm* Intern::makeForm(const std::string name, const std::string target)
{
	if (name != "ShrubberyCreationForm" && name != "RobotomyRequestForm" && name != "PresidentialPardonForm")
		std::cout << "Intern coulnd't create " << RED << name << RESET << " because it is not an official form..." << std::endl;
	std::cout << "Intern creates" << GREEN name RESET << std::endl;
	switch (name[0])
	{
		case 'S':
			return (new ShrubberyCreationForm(target));
		case 'R':
			return (new RobotomyRequestForm(target));
		case 'P':
			return (new PresidentialPardonForm(target));
	}
}
*/
