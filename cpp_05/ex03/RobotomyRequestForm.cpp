#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("A random RobotomyRequestForm form", 72, 45), _target("Default")
{
	std::cout << "RobotomyRequestForm's constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("A random RobotomyRequestForm form", 72, 47), _target(target)
{
	std::cout << "RobotomyRequestForm's parameterized constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm's destructor called" << std::endl;
}
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getSignature())
		throw (E_NotSigned("ERROR in RobotomyRequestForm: Form is not signed!"));
	if (getExecGrade() < executor.getGrade())
		throw (E_GradeTooLow("ERROR in RobotomyRequestForm: Grade too low to sign!"));

	int R = (rand() % 7) + 2;
	while (R > 0)
	{
		std::cout << "B";
		int r = (rand() % 7) + 2;
		while (r-- > 0)
			std::cout << "r";
		std::cout << "\t";
		R--;
	}
	std::cout << std::endl;
	R = rand() % 2;
	if (R)
		std::cout << "Successs: "<< _target << " have been robotomized!" << std::endl;
	else
		std::cout << "Failure: " << _target << " have not been robotomized." << std::endl;
}
// RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises, then informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, it informs that the robotomy failed.
