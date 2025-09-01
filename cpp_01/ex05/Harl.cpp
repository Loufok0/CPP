#include "Harl.hpp"

Harl::Harl (void)
{
	_name[0] = "DEBUG";
	_name[1] = "INFO";
	_name[2] = "WARNING";
	_name[3] = "ERROR";
	_f[0] = &Harl::debug;
	_f[1] = &Harl::info;
	_f[2] = &Harl::warning;
	_f[3] = &Harl::error;

}

Harl::~Harl (void) {}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn’t put enough bacon in my burger!" << std::endl << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free." << std:: endl << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int i = 0;

	while (i < NBLEVEL)
	{
		if (level.compare(_name[i]) == 0)
		{
			std::cout << "[ " << level << " ]" << std::endl;
			(this->*_f[i])();
			return ;
		}
			i++;
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}


/*
• "DEBUG" level: Debug messages contain contextual information. They are mostly
used for problem diagnosis.
Example: "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
• "INFO" level: These messages contain extensive information. They are helpful for
tracing program execution in a production environment.
Example: "I cannot believe adding extra bacon costs more money. You didn’t put
enough bacon in my burger! If you did, I wouldn’t be asking for more!"
• "WARNING" level: Warning messages indicate a potential issue in the system.
However, it can be handled or ignored.
Example: "I think I deserve to have some extra bacon for free. I’ve been coming for
years, whereas you started working here just last month."
• "ERROR" level: These messages indicate that an unrecoverable error has occurred.
This is usually a critical issue that requires manual intervention.
Example: "This is unacceptable! I want to speak to the manager now."
*/
