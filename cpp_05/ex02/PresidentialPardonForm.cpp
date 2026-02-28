#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("A random PresidentialPardonForm form", 25, 5), _target("Default")
{
	std::cout << "PresidentialPardonForm's constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("A random PresidentialPardonForm form", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm's parameterized constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm's destructor called" << std::endl;
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getSignature())
		throw (E_NotSigned("ERROR in PresidentialPardonForm: Form is not signed!"));
	if (getExecGrade() < executor.getGrade())
		throw (E_GradeTooLow("ERROR in PresidentialPardonForm: Grade too low to sign!"));
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// PresidentialPardonForm: Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox
