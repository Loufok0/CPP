#include "./Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << GREEN "constructors, << overload (geters indirectly)" RESET << std::endl;

	Form A;
	std::cout << A << std::endl;

	Form B("AUXILIAIRE", 70);
	std::cout << B << std::endl;

	Form C;
	C = B;
	std::cout << C << std::endl;






	std::cout << std::endl << std::endl;
	std::cout << GREEN "exceptions" RESET << std::endl;

	try	{
		Form E("Error", 150, 151);
	} catch (const Form::E_GradeTooHigh& e) {
		std::cout << "Error catched: " << e.what() << std::endl;
	}
	try	{
		Form E("Error", 1, -1);
	} catch (const Form::E_GradeTooLow& e)
	{
		std::cout << "Error catched: " << e.what() << std::endl;
	}

	try	{
		Form E("Error", 151, 150);
	} catch (const Form::E_GradeTooHigh& e) {
		std::cout << "Error catched: " << e.what() << std::endl;
	}
	try	{
		Form E("Error", -1, 1);
	} catch (const Form::E_GradeTooLow& e)
	{
		std::cout << "Error catched: " << e.what() << std::endl;
	}

	try	{
		Form E("Error", 150);
		E.downGradeExec();
	} catch (const Form::E_GradeTooHigh& e) {
		std::cout << "Error catched: " << e.what() << std::endl;
	}
	try	{
		Form F("Error", 1);
		F.upGradeExec();
	} catch (const Form::E_GradeTooLow& e) {
		std::cout << "Error catched: " << e.what() << std::endl;
	}

	try	{
		Form E("Error", 150);
		E.downGradeSign();
	} catch (const Form::E_GradeTooHigh& e) {
		std::cout << "Error catched: " << e.what() << std::endl;
	}
	try	{
		Form F("Error", 1);
		F.upGradeSign();
	} catch (const Form::E_GradeTooLow& e) {
		std::cout << "Error catched: " << e.what() << std::endl;
	}


	std::cout << std::endl << std::endl;
	std::cout << GREEN "upgrade and downgrade" RESET << std::endl;

	std::cout << "Before:" << std::endl;
	std::cout << A.getGrade() << std::endl;	
	A.upGrade();
	std::cout << "After:" << std::endl;
	std::cout << A.getGrade() << std::endl;	

}
