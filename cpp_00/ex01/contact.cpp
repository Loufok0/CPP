#include <iostream>
#include "contact.hpp"

Contact::Contact()
{
	_actif = false;
	//std::cout << "Constructor of Contact called" << std::endl << std::endl;
}


Contact::~Contact()
{
	//std::cout << "Desstructor of Contact called" << std::endl << std::endl;
}


void	Contact::setSecret(std::string	str)
{
	// std::cout << "Str : " << str << std::endl << std::endl;
	this->_secret = str;
}

void	Contact::setNumber(std::string	str)
{
	// std::cout << "Str : " << str << std::endl << std::endl;
	this->_number = str;
}

void	Contact::setNickName(std::string	str)
{
	// std::cout << "Str : " << str << std::endl << std::endl;
	this->_nickName = str;
}

void	Contact::setLastName(std::string	str)
{
	// std::cout << "Str : " << str << std::endl << std::endl;
	this->_lastName = str;
}

void	Contact::setFirstName(std::string	str)
{
	// std::cout << "Str : " << str << std::endl << std::endl;
	this->_firstName = str;
}

void	Contact::printInfo(std::string str, int len)
{
	int	i = 0;

	if (len > 10)
	{
		while (i < 9)
			std::cout << str[i++];
		std::cout << ".";
	}
	else
		std::cout << str;
	while (len++ < 10)
		std::cout << " ";
}

void	Contact::printContact()
{
	this->printInfo(this->_firstName, this->_firstName.length());
	std::cout << "||";
	this->printInfo(this->_lastName, this->_lastName.length());
	std::cout << "||";
	this->printInfo(this->_nickName, this->_nickName.length());
	std::cout << "||";
	std::cout << std::endl;

}

void	Contact::showContact()
{
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nick Name: " << this->_nickName << std::endl;
	std::cout << "Phone Number: " << this->_number << std::endl;
	std::cout << "Darkest Secret: " << this->_secret << std::endl;
	std::cout << std::endl;

}

void	Contact::setStatus(bool actif)
{
	this->_actif = actif;
}
bool	Contact::getStatus(void)
{
	return (this->_actif);
}
