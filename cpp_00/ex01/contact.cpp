#include <iostream>
#include "contact.hpp"

Contact::Contact()
{
	_actif = false;
	std::cout << "Constructor of Contact called" << std::endl << std::endl;
}


Contact::~Contact()
{
	std::cout << "Desstructor of Contact called" << std::endl << std::endl;
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
	std::cout << "||";
}

void	Contact::printContact()
{
	this->printInfo(this->_firstName, this->_firstName.length());
	this->printInfo(this->_lastName, this->_lastName.length());
	this->printInfo(this->_nickName, this->_nickName.length());
	std::cout << std::endl;

}
