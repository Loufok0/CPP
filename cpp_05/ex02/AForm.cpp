#include "AForm.hpp"


AForm::AForm(void) : _name("A random form"), _signature(false), _signGrade(150), _execGrade(150)
{
	// std::cout << "AForm's constructor called" << std::endl;
}

AForm::AForm(const std::string name, int signGrade, int execGrade) : _name(name), _signature(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1)
		throw E_GradeTooLow();
	if (signGrade > 150)
		throw E_GradeTooHigh();
	if (execGrade < 1)
		throw E_GradeTooLow();
	if (execGrade > 150)
		throw E_GradeTooHigh();
	// std::cout << "AForm's parameterized constructor called" << std::endl;
}

AForm::AForm(const AForm &other)
{
	this->_signGrade = other._signGrade;
	this->_execGrade = other._execGrade;
	this->_signature = other._signature;
	// std::cout << "AForm's copy constructor called" << std::endl;
}

AForm&	AForm::operator =(const AForm &other)
{
	this->_signGrade = other._signGrade;
	this->_execGrade = other._execGrade;
	this->_signature = other._signature;
	// std::cout << "AForm's copy assignation constructor called" << std::endl;
	return (*this);
}

AForm::~AForm(void)
{
	// std::cout << "AForm's destructor called" << std::endl;
}

const std::string AForm::getName(void) const
{
	return (_name);
}

int	AForm::getExecGrade(void) const
{
	return (_execGrade);
}

int	AForm::getSignGrade(void) const
{
	return (_signGrade);
}

bool	AForm::getSignature(void) const
{
	return (_signature);
}

void	AForm::upGradeExec(void)
{
	if (_execGrade <= 1)
		throw E_GradeTooLow();
	_execGrade--;
}

void	AForm::downGradeExec(void)
{
	if (_execGrade >= 150)
		throw E_GradeTooHigh();
	_execGrade++;
}

void	AForm::upGradeSign(void)
{
	if (_signGrade <= 1)
		throw E_GradeTooLow();
	_signGrade--;
}

void	AForm::downGradeSign(void)
{
	if (_signGrade >= 150)
		throw E_GradeTooHigh();
	_signGrade++;
}

std::ostream&	operator << (std::ostream &os, const AForm& f)
{
	os << f.getName();
	os << ", grade required to sign it :" << f.getSignGrade();
	os << ", grade required to execute it :" << f.getExecGrade();
	os << ", signed :" << (f.getSignature() ? "true" : "false");
	return (os);
}

void AForm::beSigned(Bureaucrat &B)
{
	if (B.getGrade() <= getSignGrade())
		_signature = true;
	else
		throw E_GradeTooLow();
}
