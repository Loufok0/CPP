#pragma once

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		const std::string _target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm&	operator =(const RobotomyRequestForm &other);
		~RobotomyRequestForm(void);

		virtual void execute(Bureaucrat const & executor) const;
};


// RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises, then informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, it informs that the robotomy failed.
