#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <cstring>
# include <unistd.h>
# include <stdlib.h>
# include "colors.hpp"

class Contact
{
	private:

		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickName;
		std::string		_number;
		std::string		_secret;
		bool			_actif;

	public:

		Contact(void);
		~Contact(void);
		bool	getStatus(void);
		void	setStatus(bool actif);
		void	setSecret(std::string	str);
		void	setNumber(std::string	str);
		void	setNickName(std::string	str);
		void	setLastName(std::string str);
		void	setFirstName(std::string	str);
		void	printContact(void);
		void	showContact(void);
		void	printInfo(std::string str, int len);
};

#endif
