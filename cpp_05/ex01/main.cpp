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
			Form E("Error", 100, 150);
			E.downGradeExec();
		} catch (const Form::E_GradeTooHigh& e) {
			std::cout << "Error catched: " << e.what() << std::endl;
		}
		try	{
			Form F("Error", 100, 1);
			F.upGradeExec();
		} catch (const Form::E_GradeTooLow& e) {
			std::cout << "Error catched: " << e.what() << std::endl;
		}
	
		try	{
			Form E("Error", 150, 100);
			E.downGradeSign();
		} catch (const Form::E_GradeTooHigh& e) {
			std::cout << "Error catched: " << e.what() << std::endl;
		}
		try	{
			Form F("Error", 1, 100);
			F.upGradeSign();
		} catch (const Form::E_GradeTooLow& e) {
			std::cout << "Error catched: " << e.what() << std::endl;
		}
	}


	{
		std::cout << std::endl << std::endl;
		std::cout << GREEN "upgrade and downgrade" RESET << std::endl;
	
		Form A;
		std::cout << "Sign level Before:" << std::endl;
		std::cout << A.getSignGrade() << std::endl;	
		A.upGradeSign();
		std::cout << "Sign level After:" << std::endl;
		std::cout << A.getSignGrade() << std::endl;	
	
	
		std::cout << "Exec level Before:" << std::endl;
		std::cout << A.getExecGrade() << std::endl;	
		A.upGradeExec();
		std::cout << "Exec level After:" << std::endl;
		std::cout << A.getExecGrade() << std::endl;
	}


	{
		std::cout << std::endl << std::endl;
		std::cout << GREEN "sign and exec" RESET << std::endl;

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
		std::cout << std::endl;
	}
}
