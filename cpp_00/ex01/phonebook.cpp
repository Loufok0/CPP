#include <iostream>
#include <unistd.h>
#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	_countacts = 0;
	std::cout << "Constructor of PhoneBook called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Desstructor of PhoneBook called" << std::endl;
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
	}

	std::cout << "==================================================================" << std::endl;
	std::cout << "||";
	std::cout << " Index\t\t" << "||";
	std::cout << " First Name\t\t"  << "||";
	std::cout << " Last Name\t\t" << "||";
	std::cout << " Nick Name\t\t" << "||" << std::endl;

	while (i < 8 && this->_contacts[i]._actif)
	{
		std::cout << i + 1 << "\t\t\t||";
		print_contact(this->_contact[i]);
		// std::cout << "==================================================================" << std::endl;
		// std::cout << "||";
		// std::cout << i + 1 << "\t\t\t||";
		// std::cout << this->_contacts[i]._firstName << "\t\t\t||";
		// std::cout << this->_contacts[i]._lastName << "\t\t\t||";
		// std::cout << this->_contacts[i]._nickName << "\t\t\t||" << std::endl;
		i++;
	}
}

void	PhoneBook::saveContact(Contact &Current)
{
	Current._actif = true;
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

void	PhoneBook::addContact(void)
{
	Contact Current;
	std::string		str;

	std::cout << "\033c";
	std::cout << "Adding contact" << std::endl << std::endl;
	sleep(1);
	std::cout << "\033c";

	std::cout << "Enter the first name of the new contact : ";
	std::getline(std::cin, str);
	Current.setFirstName(str);

	std::cout << "\033c";
	std::cout << "Enter the last name of the new contact : ";
	std::getline(std::cin, str);
	Current.setLastName(str);

	std::cout << "\033c";
	std::cout << "Enter the nick name of the new contact : ";
	std::getline(std::cin, str);
	Current.setNickName(str);

	std::cout << "\033c";
	std::cout << "Enter the phone number of the new contact : ";
	std::getline(std::cin, str);
	Current.setNumber(str);

	std::cout << "\033c";
	std::cout << "Enter the Darkest Secret of the new contact : ";
	std::getline(std::cin, str);
	Current.setSecret(str);

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

	sleep(1.5);
	std::cout << "\033c";
	std::cout << "Enter a command!" << std::endl;
}


int	main()
{
	std::string		str;
	PhoneBook		phonebook;

	entrance();
	while (str != "EXIT")
	{
		std::getline(std::cin, str);
		if (str == "ADD")
		{
			std::cout << "\033c";
			phonebook.addContact();
			std::cout << "Contact added!" << std::endl << std::endl;
		}
		else if (str == "SEARCH")
		{
			std::cout << "\033c";
			phonebook.showContacts();
		}
		else
		{
			std::cout << "Error, command not found!" << std::endl;
			sleep(1);
			std::cout << "\033c";
			std::cout << "Enter a command!" << std::endl;
		}
	}
}
