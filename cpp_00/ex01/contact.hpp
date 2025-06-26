#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include "colors.hpp"

class Contact
{
	private:
		;
	public:
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickName;
		std::string		_number;
		std::string		_secret;
		bool			_actif;

		Contact(void);
		~Contact(void);

	void	setSecret(std::string	str);
	void	setNumber(std::string	str);
	void	setNickName(std::string	str);
	void	setLastName(std::string str);
	void	setFirstName(std::string	str);
};

#endif
