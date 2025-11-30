#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include "colors.hpp"


class Form
{
	private:
		const std::string _name;
		bool _signature;
		int _signGrade;
		int _execGrade;

	public:
		Form(void);
		Form(const std::string name, int signGrade, int execGrade);
		Form(const Form &other);
		Form&	operator =(const Form &other);
		~Form(void);

		const std::string getName(void) const;
		int	getExecGrade(void) const;
		int	getSignGrade(void) const;
		bool	getSignature(void) const;
		void	upGradeExec(void);
		void	downGradeExec(void);
		void	upGradeSign(void);
		void	downGradeSign(void);


		class E_GradeTooHigh : public std::exception
		{
			private:
				const char* _msg;

			public:
				E_GradeTooHigh(void): _msg("ERROR: Grade given to Form is too high!") {}
				const char* what() const throw() {return _msg;}
		};

		class E_GradeTooLow : public std::exception
		{
			private:
				const char* _msg;

			public:
				E_GradeTooLow(void): _msg("ERROR: Grade given to Form is too low!") {}
				const char* what() const throw() {return _msg;}
		};
};

std::ostream&	operator << (std::ostream &os, const Form& f);
