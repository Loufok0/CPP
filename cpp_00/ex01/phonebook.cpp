#include <iostream>
#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "Constructor of PhoneBook called" << std::endl << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Desstructor of PhoneBook called" << std::endl << std::endl;
}


void	PhoneBook::showContacts()
{
	int	i = 0;
	while (i < 8 && this->_contacts[i]._actif)
	{
		std::cout << "Contact " << i << ":" << "actif : " << this->_contacts[i]._actif << std::endl << std::endl;
		std::cout << "First Name : " << this->_contacts[i]._firstName << std::endl;
		std::cout << "Last Name : " << this->_contacts[i]._lastName << std::endl;
		std::cout << "Nick Name : " << this->_contacts[i]._nickName << std::endl <<  std::endl;

		i++;
	}

}

void	PhoneBook::saveContact(Contact &Current)
{
	Current._actif = true;
	if (this->_countacts == 0)
		this->_oldest = 0;
	if (this->_countacts == 7)
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

	std::cout << "Adding contact" << std::endl << std::endl;

	std::cout << "Enter the first name of the new contact : ";
	std::getline(std::cin, str);
	Current.setFirstName(str);

	std::cout << "Enter the last name of the new contact : ";
	std::getline(std::cin, str);
	Current.setLastName(str);

	std::cout << "Enter the nick name of the new contact : ";
	std::getline(std::cin, str);
	Current.setNickName(str);

	std::cout << "Enter the phone number of the new contact : ";
	std::getline(std::cin, str);
	Current.setNumber(str);

	PhoneBook::saveContact(Current);
}



int	main()
{
	std::string		str;
	PhoneBook		phonebook;

	phonebook._countacts = 0;
	while (str != "EXIT")
	{
		std::getline(std::cin, str);
		if (str == "ADD")
		{
			phonebook.addContact();
			std::cout << "Contact added!" << std::endl << std::endl;
		}
		else if (str == "SEARCH")
			std::cout << "You searching what ?" << std::endl << std::endl;
		else if (str == "SHOW")
		{
			phonebook.showContacts();
			str = "hello there";
		}
	}
}
