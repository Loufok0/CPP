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
