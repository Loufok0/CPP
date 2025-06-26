#include <iostream>
#include "phonebook.hpp"

class Contact
{
	private:
		;
	public:
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickName;
		std::string		_phone;

		Contact()
		{
			name = "NULL";
			phone = "NULL";
		};

		Contact(const std::string n, const std::string p);

		std::string	getName() {return (_name);};

};
