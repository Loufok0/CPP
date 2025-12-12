#pragma once

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		const std::string _target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm&	operator =(const PresidentialPardonForm &other);
		~PresidentialPardonForm(void);

		virtual void execute(Bureaucrat const & executor) const;
};


// PresidentialPardonForm: Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox
