#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << GREEN "constructors, << overload (geters indirectly)" RESET << std::endl;

	Bureaucrat A;
	std::cout << A << std::endl;

	Bureaucrat B("AUXILIAIRE", 70);
	std::cout << B << std::endl;

	Bureaucrat C;
	C = B;
	std::cout << C << std::endl;






	std::cout << std::endl << std::endl;
	std::cout << GREEN "exceptions" RESET << std::endl;

	try	{
		Bureaucrat E("Error", 151);
	} catch (const Bureaucrat::E_GradeTooHigh& e) {
		std::cout << "Error catched: " << e.what() << std::endl;
	}
	try	{
		Bureaucrat E("Error", -1);
	} catch (const Bureaucrat::E_GradeTooLow& e)
	{
		std::cout << "Error catched: " << e.what() << std::endl;
	}

	try	{
		Bureaucrat E("Error", 150);
		E.downGrade();
	} catch (const Bureaucrat::E_GradeTooHigh& e) {
		std::cout << "Error catched: " << e.what() << std::endl;
	}
	try	{
		Bureaucrat F("Error", 1);
		F.upGrade();
	} catch (const Bureaucrat::E_GradeTooLow& e) {
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
