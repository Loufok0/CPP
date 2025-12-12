#include "./Bureaucrat.hpp"
#include "AForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"

int	main(void)
{
	{
		ShrubberyCreationForm Sd;
		RobotomyRequestForm Rd;
		PresidentialPardonForm Pd;
	}
	std::cout << std::endl << std::endl;

	{
		ShrubberyCreationForm S("home");
		RobotomyRequestForm R("home");
		PresidentialPardonForm P("home");
	}
	std::cout << std::endl << std::endl;

	{
		Bureaucrat B("Tom", 50);
		ShrubberyCreationForm S("home");
		B.signAForm(S);
		try {
			S.execute(B);
		} catch (const ShrubberyCreationForm::E_NotSigned& e) {
			std::cout << "Error catched: " << e.what() << std::endl;
		} catch (const ShrubberyCreationForm::E_GradeTooLow& e) {
			std::cout << "Error catched: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;

	{
		Bureaucrat B("Tom", 30);
		RobotomyRequestForm R("Baptist");
		B.signAForm(R);
		try {
			R.execute(B);
			R.execute(B);
			R.execute(B);
			R.execute(B);
		} catch (const RobotomyRequestForm::E_NotSigned& e) {
			std::cout << "Error catched: " << e.what() << std::endl;
		} catch (const RobotomyRequestForm::E_GradeTooLow& e) {
			std::cout << "Error catched: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
	

	{
		Bureaucrat B("Tom", 3);
		PresidentialPardonForm P("FOOOOOORM");
		B.signAForm(P);
		try {
			P.execute(B);
		} catch (const PresidentialPardonForm::E_NotSigned& e) {
			std::cout << "Error catched: " << e.what() << std::endl;
		} catch (const PresidentialPardonForm::E_GradeTooLow& e) {
			std::cout << "Error catched: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;


	{

		Bureaucrat B("MOM", 1);
		Bureaucrat L("Little bro", 150);

		ShrubberyCreationForm S("home");
		RobotomyRequestForm R("Baptist");
		PresidentialPardonForm P("FOOOOOORM");

		try {
			L.executeForm(S);
		} catch (AForm::E_NotSigned& e) {
			std::cout << "Error catched: " << e.what() << std::endl;
		}
		try {
			L.executeForm(R);
		} catch (AForm::E_NotSigned& e) {
			std::cout << "Error catched: " << e.what() << std::endl;
		}
		try {
			L.executeForm(P);
		} catch (AForm::E_NotSigned& e) {
			std::cout << "Error catched: " << e.what() << std::endl;
		}
		
		B.signAForm(S);
		B.signAForm(R);
		B.signAForm(P);

		try {
			L.executeForm(S);
		} catch (AForm::E_GradeTooLow& e) {
			std::cout << "Error catched: " << e.what() << std::endl;
		}
		try {
			L.executeForm(R);
		} catch (AForm::E_GradeTooLow& e) {
			std::cout << "Error catched: " << e.what() << std::endl;
		}
		try {
			L.executeForm(P);
		} catch (AForm::E_GradeTooLow& e) {
			std::cout << "Error catched: " << e.what() << std::endl;
		}


		B.executeForm(S);
		B.executeForm(R);
		B.executeForm(P);
	}
	std::cout << std::endl << std::endl;
}
