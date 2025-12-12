#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("A random ShrubberyCreationForm form", 145, 137), _target("Default")
{
	std::cout << "ShrubberyCreationForm's constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("A random ShrubberyCreationForm form", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm's parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm's destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getSignature())
		throw (E_NotSigned("ERROR in ShrubberyCreationForm: Form is not signed!"));
	if (getExecGrade() < executor.getGrade())
		throw (E_GradeTooLow("ERROR in ShrubberyCreationForm: Grade too low to sign!"));
	std::ofstream out ((_target + "_shrubbery").c_str());
	
	int	i = 0;
	while (i < 3)
	{
		out << " _____ ____  _____ _____ ____  " << std::endl;
		out << "|_   _|  _ \\| ____| ____/ ___| " << std::endl;
		out << "  | | | |_) |  _| |  _| \\___ \\ " << std::endl;
		out << "  | | |  _ <| |___| |___ ___) |" << std::endl;
		out << "  |_| |_| \\_\\_____|_____|____/ " << std::endl << std::endl;
		i++;
	}
	std::cout << "Trees have been planted in " << _target << "!" << std::endl;
}

// ShrubberyCreationForm: Required grades: sign 145, exec 137
// Creates a file <target>_shrubbery in the working directory and writes ASCII trees
// inside it.
