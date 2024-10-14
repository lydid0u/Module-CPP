#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
	public:
    Contact Contacts[8];
    int i;
    void add();
    void seaarch();
    PhoneBook() : i(0) {}
};

#endif