#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include "colors.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signature;
		int _signGrade;
		int _execGrade;

	public:
		AForm(void);
		AForm(const std::string name, int signGrade, int execGrade);
		AForm(const AForm &other);
		AForm&	operator =(const AForm &other);
		virtual ~AForm(void) = 0;

		const std::string getName(void) const;
		int	getExecGrade(void) const;
		int	getSignGrade(void) const;
		bool	getSignature(void) const;

		void beSigned(Bureaucrat &B);

		class E_GradeTooHigh : public std::exception
		{
			private:
				const char* _msg;

			public:
				E_GradeTooHigh(void): _msg(RED "ERROR in Aform: Grade given is too high!" RESET) {}
				const char* what() const throw() {return _msg;}
		};

		class E_GradeTooLow : public std::exception
		{
			private:
				const std::string _msg;

			public:
				E_GradeTooLow(void): _msg(RED "ERROR in Aform: Grade given is too low!" RESET) {}
				E_GradeTooLow(std::string msg) : _msg(std::string(RED) + msg + RESET) {};
				const char* what() const throw() {return _msg.c_str();}
			    virtual ~E_GradeTooLow() throw() {};
		};

		virtual void execute(Bureaucrat const & executor) const = 0;


		class E_NotSigned : public std::exception
		{
			private:
				const std::string _msg;
			public:
				E_NotSigned(std::string msg) : _msg(std::string(RED) + msg + RESET) {};
				const char* what() const throw() {return _msg.c_str();}
			    virtual ~E_NotSigned() throw() {};
		};
};

std::ostream&	operator << (std::ostream &os, const AForm& f);
