#include "./Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	{
		std::cout << GREEN "constructors, << overload (geters indirectly)" RESET << std::endl;
	
		Form A;
		std::cout << A << std::endl;
	
		Form B("AUXILIAIRE", 70, 100);
		std::cout << B << std::endl;
	
		Form C;
		C = B;
		std::cout << C << std::endl;
	}





	{
		std::cout << std::endl << std::endl;
		std::cout << GREEN "Exceptions:" RESET << std::endl;
	
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
	
	}


	{
		std::cout << std::endl << std::endl;
		std::cout << GREEN "Get grades:" RESET << std::endl;
	
		Form A;
		std::cout << "Sign: " << A.getSignGrade() << std::endl;	
		std::cout << "Exec: " << A.getExecGrade() << std::endl;	
	}


	{
		std::cout << std::endl << std::endl;
		std::cout << GREEN "Sign:" RESET << std::endl;

		Bureaucrat B("Boss", 1);
		Form F("big form", 1, 1);
		Bureaucrat b("Karen", 100);
		Form f("little form", 100, 100);

		{
			std::cout << std::endl;
			B.signForm(F);
			B.signForm(f);
		}
		{
			std::cout << std::endl;
			b.signForm(F);
			b.signForm(f);
		}

//		{
//			std::cout << std::endl;
//			B.execForm(F);
//			B.execForm(f);
//		}
//		{
//			std::cout << std::endl;
//			b.execForm(F);
//			b.execForm(f);
//		}
		std::cout << std::endl;
	}
}
