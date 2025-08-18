#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include "contact.hpp"

class PhoneBook
{
	private:

		Contact		_contacts[8];
		int			_countacts;
		int			_oldest;

	public:

		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(void);
		void	saveContact(Contact &Current);
		void	showContacts(void);
};

#endif
