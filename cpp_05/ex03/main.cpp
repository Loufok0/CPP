#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern I;
	AForm *F1 = I.makeForm(std::string("aesd"), std::string("sergdv"));
	AForm *F2 = I.makeForm(std::string("ShrubberyCreationForm"), std::string("Shrub"));
	AForm *F3 = I.makeForm(std::string("RobotomyRequestForm"), std::string("Tom"));
	AForm *F4 = I.makeForm(std::string("PresidentialPardonForm"), std::string("Boss"));
	std::cout << std::endl << std::endl;

	delete F2;
	delete F3;
	delete F4;
	(void)F1;
}
