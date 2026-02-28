#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("A random guy"), _grade(150)
{
	std::cout << "Bureaucrat's constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw E_GradeTooLow();
	if (grade > 150)
		throw E_GradeTooHigh();
	std::cout << "Bureaucrat's parameterized constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	this->_grade = other._grade;
	std::cout << "Bureaucrat's copy constructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator =(const Bureaucrat &other)
{
	this->_grade = other._grade;
	std::cout << "Bureaucrat's copy assignation constructor called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat's destructor called" << std::endl;
}

const std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::upGrade(void)
{
	if (_grade <= 1)
		throw E_GradeTooLow();
	_grade--;
}

void	Bureaucrat::downGrade(void)
{
	if (_grade >= 150)
		throw E_GradeTooHigh();
	_grade++;
}

std::ostream&	operator << (std::ostream &os, const Bureaucrat& b)
{
	std::stringstream ss;
	ss << b.getGrade();
	os << b.getName() << ", bureaucrat grade " << ss.str();
	return (os);
}

void	Bureaucrat::signAForm(AForm &F)
{
	try {
		F.beSigned(*this);
		std::cout << getName() << " signed " << F.getName() << std::endl;
	} catch (const AForm::E_GradeTooLow& e){
		std::cout << getName() << " couldn’t sign " << F.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try {
		form.execute(*this);
	} catch (AForm::E_GradeTooLow& e) {
		std::cout << e.what() << std::endl;
		return ;
	} catch (AForm::E_NotSigned& e) {
		std::cout << e.what() << std::endl;
		return ;
	}
		std::cout << getName() << " executed " << form.getName() << std::endl;
}
