#include "PhoneBook.hpp"
#include <stdio.h>

PhoneBook::PhoneBook() : i(1) {}

PhoneBook::~PhoneBook(){}

int	PhoneBook::check_name(std::string str)
{
	for (unsigned long i = 0; i < str.length(); i++)
	{
		if (!isalpha(str[i]))
			return (1);
	}
	return (0);
}

int	PhoneBook::check_nickname(std::string str)
{
	for (unsigned long i = 0; i < str.length(); i++)
	{
		if (!isalnum(str[i]))
			return (1);
	}
	return (0);
}

int	PhoneBook::check_number(std::string str)
{
	if (str[0] != '0' || str.length() != 10)
		return (1);
	for (unsigned long i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (1);
	}
	return (0);
}

void PhoneBook::EighthContact()
{
	std::string str;
    while (1)
    {
	    std::cout << "Please enter first name :" << std::endl;
	    getline(std::cin, str);
	    if (!check_name(str))
	    {
        	Contacts[3].SetFirstName(str);
            break ;
        }
	    else
	    	std::cout << RED << "Error a character is incorrect :(" << RESET << std::endl;
    }
    while (1)
    {
	    std::cout << "Please enter last name :" << std::endl;
	    getline(std::cin, str);
	    if (!check_name(str))
        {
	    	Contacts[3].SetLastName(str);
            break ;
        }
	    else
	    	std::cout << RED << "Error a character is incorrect :(" << RESET << std::endl;
    }
    while (1)
    {
	    std::cout << "Please enter Nickname :" << std::endl;
	    getline(std::cin, str);
	    if (!check_nickname(str))
        {
	    	Contacts[3].SetNickname(str);
            break ;
        }
	    else
	    	std::cout << RED << "Error a character is incorrect :(" << RESET << std::endl;
    }
    while (1)
    {
	    std::cout << "Please enter your phone number :" << std::endl;
	    getline(std::cin, str);
	    if (!check_number(str) || str[0] == '*')
        {
	    	Contacts[3].SetPhoneNumber(str);
            break;
        }
	    else
	    	std::cout << RED << "Please enter a valid phone number (starting with 0 and 10 digits)" << RESET << std::endl;
    }
	std::cout << "Please tell me your darkest secret :" << std::endl;
	getline(std::cin, str);
	Contacts[3].SetDarkestSecret(str);
	i = 3;
}

void PhoneBook::add()
{
	std::string str;
	if (i <= 2)
	{
        while (1)
        {
		    std::cout << "Please enter first name :" << std::endl;
		    getline(std::cin, str);
		    if (!check_name(str))
		    {
            	Contacts[i].SetFirstName(str);
                break ;
            }
		    else
		    	std::cout << RED << "Error a character is incorrect :(" << RESET << std::endl;
        }
        while (1)
        {
		    std::cout << "Please enter last name :" << std::endl;
		    getline(std::cin, str);
		    if (!check_name(str))
            {
		    	Contacts[i].SetLastName(str);
                break ;
            }
		    else
		    	std::cout << RED << "Error a character is incorrect :(" << RESET << std::endl;
        }
        while (1)
        {
		    std::cout << "Please enter Nickname :" << std::endl;
		    getline(std::cin, str);
		    if (!check_nickname(str))
            {
		    	Contacts[i].SetNickname(str);
                break ;
            }
		    else
		    	std::cout << RED << "Error a character is incorrect :(" << RESET << std::endl;
        }
        while (1)
        {
		    std::cout << "Please enter your phone number :" << std::endl;
		    getline(std::cin, str);
		    if (!check_number(str) || str[0] == '*')
            {
		    	Contacts[i].SetPhoneNumber(str);
                break;
            }
		    else
		    	std::cout << RED << "Please enter a valid phone number (starting with 0 and 10 digits)" << RESET << std::endl;
        }
		std::cout << "Please tell me your darkest secret :" << std::endl;
		getline(std::cin, str);
		Contacts[i].SetDarkestSecret(str);
		i++;
	}
	else
		EighthContact();
}

int PhoneBook::index_to_display(std::string to_display)
{   
	if (isdigit(to_display[0]) && to_display.length() == 1)
	{
		if (to_display[0] - '0' > i ||to_display[0] - '0' == 0)
			return (-1);
		else
			return (to_display[0] - '0');
	}
	else
		return (-1);
}

std::string truncate(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0, 10 - 1) + '.';
	else
		return str;
}

void PhoneBook::search()
{  
	int index;
    int tmp = 0;
	std::string to_display;
	std::cout << std::right;
	std::cout << std::setw(10) << YELLOW << "index|" << std::setw(10) << "first name|" << std::setw(10) << " last name|" << std::setw(10) << "  nickname|" << RESET << std::endl; 
	if (i <= 3)
    {
        tmp = i;
        i = i - 1;
    }
    for (int j = 1; j <= i; j++)
	{
		std::cout << YELLOW << std::setw(10) << j << "|" << RESET;
		std::cout << YELLOW << std::setw(10) <<  truncate(Contacts[j].GetFirstName()) << "|" << RESET;
		std::cout << YELLOW << std::setw(10) <<  truncate(Contacts[j].GetLastName()) << "|" << RESET;
		std::cout << YELLOW << std::setw(10) <<  truncate(Contacts[j].GetNickname()) << "|" << RESET;
		std::cout << YELLOW << std::endl << RESET;
	}
	while (1)
	{
		std::cout << i << "Please enter the index of the contact to display" << std::endl;
		getline(std::cin, to_display);
		if (index_to_display(to_display) == -1)
			std::cout << RED << "Error ! Please enter a valid index !" << RESET << std::endl;
		else
		{
			index = index_to_display(to_display);
			break ;
		}		
	}
    if (tmp)
    {
        i = tmp;
    }
	std::cout << YELLOW << "First name : " <<  Contacts[index].GetFirstName() << RESET << std::endl;
	std::cout << YELLOW << "Last name : " <<  Contacts[index].GetLastName() << RESET << std::endl;
	std::cout << YELLOW << "Nickname : " <<  Contacts[index].GetNickname() << RESET << std::endl;
	std::cout << YELLOW << "Phone number : " <<  Contacts[index].GetPhoneNumber() << RESET << std::endl;
	std::cout << YELLOW << "Darkest secret : " <<  Contacts[index].GetDarkestSecret() << RESET << std::endl;
}