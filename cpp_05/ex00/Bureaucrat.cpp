#include "Bureaucrat.hpp"

void	Bureaucrat::Bureaucrat(void) : _name("A random guy") _grade(150)
{
	std::cout << "Bureaucrat's constructor called" << std::endl;
}

void	Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw E_GradeTooLow()
	if (grade > 150)
		throw E_GradeTooHight()
	std::cout << "Bureaucrat's parameterized constructor called" << std::endl;
}

void	Bureaucrat::Bureaucrat(Bureaucrat &other)
{
	std::cout << "Bureaucrat's copy constructor called" << std::endl;

}

Bureaucrat*	Bureaucrat::operator =(Bureaucrat &other)
{
	std::cout << "Bureaucrat's copy assignation constructor called" << std::endl;

}

void		Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat's desstructor called" << std::endl;
}
