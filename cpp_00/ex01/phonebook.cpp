#include "phonebook.hpp"
#include <sstream>

PhoneBook::PhoneBook()
{
	_countacts = 0;
	std::cout << "Constructor of PhoneBook called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Desstructor of PhoneBook called" << std::endl;
}

bool isNumber(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return !str.empty();
}

void	PhoneBook::showContacts()
{
	int	i = 0;

	if (this->_countacts == 0)
	{
		std::cout << "No contacts for the moment! " << std::endl << std::endl;
		sleep(1.5);
		std::cout << "\033c";
		std::cout << "Enter a command!" << std::endl;
		return ;
	}

	std::cout << "==================================================" << std::endl;
	std::cout << "||";
	std::cout << "Index     " << "||";
	std::cout << "First Name"  << "||";
	std::cout << "Last Name " << "||";
	std::cout << "Nick Name " << "||" << std::endl;
	std::cout << "==================================================" << std::endl;

	while (i < 8 && this->_contacts[i].getStatus())
	{
		std::cout << "||";
		std::cout << i << "         ||";
		this->_contacts[i].printContact();
		i++;
	}
	std::cout << "==================================================" << std::endl << std::endl;


	std::string	str = "hello there";
	int			n = 111;

	std::cout << "Wich contact (index) do you want to print ?" << std::endl;
	std::getline(std::cin, str);
	n = std::atoi(str.c_str());
	while (!isNumber(str) || n < 0 || n > this->_countacts - 1)
	{
		std::cout << "\033[F\033[F\033[F";
		std::cout << "Error: Enter a number from 0 to " << this->_countacts - 1 << std::endl;
		std::cout << "Wich contact (index) do you want to print ?" << std::endl;
		std::getline(std::cin, str);
		n = std::atoi(str.c_str());
	}
	this->_contacts[n].showContact();

}

void	PhoneBook::saveContact(Contact &Current)
{
	Current.setStatus(true);
	if (this->_countacts == 0)
		this->_oldest = 0;
	if (this->_countacts == 8)
	{
		this->_contacts[this->_oldest] = Current;
		this->_oldest++;
		if (this->_oldest == 8)
			this->_oldest = 0;
	}
	else
		this->_contacts[this->_countacts++] = Current;
}

std::string	PhoneBook::loop(std::string ask)
{
	std::string		str;

	std::cout << "\033c";
	std::cout << "Enter the " << ask << " of the new contact : ";
	std::getline(std::cin, str);
	while (str.length() == 0)
	{
		std::cout << "String not accepted..." << std::endl;
		std::getline(std::cin, str);
		std::cout << "\033[F\033[F";
	}
	return (str);
}

void	PhoneBook::addContact(void)
{
	Contact Current;
	std::string str;
	int	num;

	std::cout << "\033c";
	std::cout << "Adding contact" << std::endl << std::endl;
	sleep(0.5);

	Current.setFirstName(loop("first name"));
	Current.setLastName(loop("last name"));
	Current.setNickName(loop("nickname"));

	std::cout << "\033c";
	std::cout << "Enter the phone number of the new contact : ";

	std::getline(std::cin, str);
	std::istringstream	ss(str);
	ss >> num;
	while (str.length() == 0 || ! num)
	{
		std::cout << "Number not accepted..." << std::endl;
		std::getline(std::cin, str);
		std::istringstream	ss(str);
		ss >> num;
		std::cout << ss << num;
		std::cout << "\033[F\033[F";
	}
	Current.setNumber(str);
	Current.setSecret(loop("darkest secret"));

	PhoneBook::saveContact(Current);
	std::cout << "\033c";
}

void	entrance()
{
	std::cout << "\033c";

	std::cout << "__      __   _                    _       " << BLUE " ___ _                 ___           _" RESET << std::endl;
	std::cout << "\\ \\    / /__| |__ ___ _ __  ___  | |_ ___ " << BLUE "| _ \\ |_  ___ _ _  ___| _ ) ___  ___| |__" RESET << std::endl;
	std::cout << " \\ \\/\\/ / -_) / _/ _ \\ '  \\/ -_) |  _/ _ \\" << BLUE "|  _/ ' \\/ _ \\ ' \\/ -_) _ \\/ _ \\/ _ \\ / /" RESET << std::endl;
	std::cout << "  \\_/\\_/\\___|_\\__\\___/_|_|_\\___|  \\__\\___/" << BLUE "|_| |_||_\\___/_||_\\___|___/\\___/\\___/_\\_\\" RESET << std::endl;

	sleep(1);
	std::cout << "\033c";
	std::cout << "Enter a command!" << std::endl;
}


int	main()
{
	std::string		str;
	PhoneBook		phonebook;

	entrance();
	while (str != "EXIT" || str != "exit")
	{
		std::getline(std::cin, str);
		if (str == "ADD" || str == "add")
		{
			std::cout << "\033c";
			phonebook.addContact();
			std::cout << "Contact added!" << std::endl << std::endl;
		}
		else if (str == "SEARCH" || str == "search")
		{
			std::cout << "\033c";
			phonebook.showContacts();
			std::cout << std::endl << "Enter a command!" << std::endl;
			continue;
		}
		else if (str == "EXIT" || str == "exit")
			continue;
		else
			std::cout << "Error, command found!" << std::endl;
		sleep(1);
		std::cout << "\033c";
		std::cout << "Enter a command!" << std::endl;
	}
}
