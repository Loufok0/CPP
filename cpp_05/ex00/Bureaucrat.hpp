#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat :
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat &other);
		Bureaucrat *operator =(Bureaucrat &other);
		~Bureaucrat(void);

		class E_GradeTooHigh : public std::exception
		{
			private:
				const std::string _msg;

			public:
				E_GradeTooHigh(void) _msg("ERROR: Grade given is too high!") {}
				const std::string what() const throw() {return _msg;}
		}

		class E_GradeTooLow : public std::exception
		{
			private:
				const std::string _msg;

			public:
				E_GradeTooLow(void) _msg("ERROR: Grade given is too low!") {}
				const std::string what() const throw() {return _msg;}
		}
}
