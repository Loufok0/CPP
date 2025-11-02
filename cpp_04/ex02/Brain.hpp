#pragma once

#include <iostream>

class Brain
{
	protected:

		std::string _ideas[100];

	public:


		Brain();
		Brain(const std::string *ideas);
		Brain(const Brain &other);
		Brain& operator = (const Brain &other);
		~Brain();

		void	setIdeas(const std::string *ideas);
		void	thoughts(void)	const;
};
