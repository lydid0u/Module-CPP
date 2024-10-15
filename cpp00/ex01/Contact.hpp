#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "PhoneBook.hpp"


class Contact
{
	public:
	std::string	FirstName;
	std::string	LastName;
	std::string	Nickname;
	std::string PhoneNumber;
	std::string	DarkestSecret;
};

#endif