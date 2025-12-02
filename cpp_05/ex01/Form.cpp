#include "Form.hpp"

Form::Form(void) : _name("A random form"), _signature(false), _signGrade(150), _execGrade(150)
{
	std::cout << "Form's constructor called" << std::endl;
}

Form::Form(const std::string name, int signGrade, int execGrade) : _name(name), _signature(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1)
		throw E_GradeTooLow();
	if (signGrade > 150)
		throw E_GradeTooHigh();
	if (execGrade < 1)
		throw E_GradeTooLow();
	if (execGrade > 150)
		throw E_GradeTooHigh();
	std::cout << "Form's parameterized constructor called" << std::endl;
}

Form::Form(const Form &other)
{
	this->_signGrade = other._signGrade;
	this->_execGrade = other._execGrade;
	this->_signature = other._signature;
	std::cout << "Form's copy constructor called" << std::endl;
}

Form&	Form::operator =(const Form &other)
{
	this->_signGrade = other._signGrade;
	this->_execGrade = other._execGrade;
	this->_signature = other._signature;
	std::cout << "Form's copy assignation constructor called" << std::endl;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Form's destructor called" << std::endl;
}

const std::string Form::getName(void) const
{
	return (_name);
}

int	Form::getExecGrade(void) const
{
	return (_execGrade);
}

int	Form::getSignGrade(void) const
{
	return (_signGrade);
}

bool	Form::getSignature(void) const
{
	return (_signature);
}

void	Form::upGradeExec(void)
{
	if (_execGrade <= 1)
		throw E_GradeTooLow();
	_execGrade--;
}

void	Form::downGradeExec(void)
{
	if (_execGrade >= 150)
		throw E_GradeTooHigh();
	_execGrade++;
}

void	Form::upGradeSign(void)
{
	if (_signGrade <= 1)
		throw E_GradeTooLow();
	_signGrade--;
}

void	Form::downGradeSign(void)
{
	if (_signGrade >= 150)
		throw E_GradeTooHigh();
	_signGrade++;
}

std::ostream&	operator << (std::ostream &os, const Form& f)
{
	os << f.getName();
	os << ", grade required to sign it :" << f.getSignGrade();
	os << ", grade required to execute it :" << f.getExecGrade();
	os << ", signed :" << (f.getSignature() ? "true" : "false");
	return (os);
}

void Form::beSigned(Bureaucrat &B)
{
	if (B.getGrade() <= getSignGrade())
		_signature = true;
	else
		throw E_GradeTooLow();
}
