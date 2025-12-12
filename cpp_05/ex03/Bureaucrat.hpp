#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include "colors.hpp"
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator =(const Bureaucrat &other);
		~Bureaucrat(void);

		const std::string getName(void) const;
		int	getGrade(void) const;
		void	upGrade(void);
		void	downGrade(void);

		void	signAForm(AForm &F);

		class E_GradeTooHigh : public std::exception
		{
			private:
				const char* _msg;

			public:
				E_GradeTooHigh(void): _msg("ERROR: Grade given to Bureaucrat is too high!") {}
				const char* what() const throw() {return _msg;}
		};

		class E_GradeTooLow : public std::exception
		{
			private:
				const char* _msg;

			public:
				E_GradeTooLow(void): _msg("ERROR: Grade given to Bureaucrat is too low!") {}
				const char* what() const throw() {return _msg;}
		};

		void executeForm(AForm const & form) const;

};
	std::ostream&	operator << (std::ostream &os, const Bureaucrat& b);
