#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include "contact.hpp"

class PhoneBook
{
	private:
		;
	public:
		Contact		_contacts[8];
		int			_countacts;
		int			_oldest;

	PhoneBook(void);
	~PhoneBook(void);

	void	addContact(void);
	void	saveContact(Contact &Current);
	void	showContacts(void);
};

#endif
