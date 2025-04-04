#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <cctype>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int 	_nbContacts;
		int 	_index;

	public:
		PhoneBook();
		~PhoneBook();

		void addContact(void);
		void searchContact(void);
};

#endif