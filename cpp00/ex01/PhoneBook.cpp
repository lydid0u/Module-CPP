/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:57:14 by lboudjel          #+#    #+#             */
/*   Updated: 2024/10/17 17:57:14 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <stdio.h>

PhoneBook::PhoneBook() : i(0), eight(0) {}

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
	    std::cout << GREEN << "Please enter first name :" << RESET << std::endl;
	    getline(std::cin, str);
	    if (std::cin.eof())
            return ;
		if (!check_name(str))
	    {
        	Contacts[7].SetFirstName(str);
            break ;
        }
	    else
	    	std::cout << RED << "Error a character is incorrect :(" << RESET << std::endl;
    }
    while (1)
    {
	    std::cout << GREEN << "Please enter last name :" << RESET << std::endl;
	    getline(std::cin, str);
	    if (std::cin.eof())
            return ;
		if (!check_name(str))
        {
	    	Contacts[7].SetLastName(str);
            break ;
        }
	    else
	    	std::cout << RED << "Error a character is incorrect :(" << RESET << std::endl;
    }
    while (1)
    {
	    std::cout << GREEN << "Please enter Nickname :" << RESET << std::endl;
	    getline(std::cin, str);
	    if (std::cin.eof())
            return ;
		if (!check_nickname(str))
        {
	    	Contacts[7].SetNickname(str);
            break ;
        }
	    else
	    	std::cout << RED << "Error a character is incorrect :(" << RESET << std::endl;
    }
    while (1)
    {
	    std::cout << GREEN << "Please enter your phone number :" << RESET << std::endl;
	    getline(std::cin, str);
	    if (std::cin.eof())
            return ;
		if (!check_number(str) || str[0] == '*')
        {
	    	Contacts[7].SetPhoneNumber(str);
            break;
        }
	    else
	    	std::cout << RED << "Please enter a valid phone number (starting with 0 and 10 digits)" << RESET << std::endl;
    }
	std::cout << GREEN << "Please tell me your darkest secret :" << RESET << std::endl;
	getline(std::cin, str);
	Contacts[7].SetDarkestSecret(str);
	i = 7;
	eight = 1;
	
}

void PhoneBook::add()
{
	std::string str;
	if (i < 7)
	{
        while (1)
        {
		    std::cout << GREEN << "Please enter first name :" << RESET << std::endl;
		    getline(std::cin, str);
		    if (std::cin.eof())
            return ;
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
		    std::cout << GREEN << "Please enter last name :" << RESET << std::endl;
		    getline(std::cin, str);
		    if (std::cin.eof())
            return ;
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
		    std::cout << GREEN << "Please enter Nickname :" << RESET << std::endl;
		    getline(std::cin, str);
		    if (std::cin.eof())
            return ;
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
		    std::cout << GREEN << "Please enter your phone number :" << RESET << std::endl;
		    getline(std::cin, str);
		    if (std::cin.eof())
            return ;
			if (!check_number(str) || str[0] == '*')
            {
		    	Contacts[i].SetPhoneNumber(str);
                break;
            }
		    else
		    	std::cout << RED << "Please enter a valid phone number (starting with 0 and 10 digits)" << RESET << std::endl;
        }
		std::cout << GREEN << "Please tell me your darkest secret :" << RESET << std::endl;
		getline(std::cin, str);
		Contacts[i].SetDarkestSecret(str);
		i++;
	}
	else
		EighthContact();
}

int PhoneBook::index_to_display(std::string to_display)
{   
	int tmp;
	if (eight)
		tmp = i;
	else
		tmp = i - 1;
	if (isdigit(to_display[0]) && to_display.length() == 1)
	{
		if (to_display[0] - '0' == 0)
			return (to_display[0] - '0');
		else if (to_display[0] - '0' > tmp)
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
    int j;
	int tmp;
	if (eight)
		tmp = i + 1;
	else
		tmp = i;
	std::string to_display;
	std::cout << std::right;
	std::cout << std::setw(10) << YELLOW << "index|" << std::setw(10) << "first name|" << std::setw(10) << " last name|" << std::setw(10) << "  nickname|" << RESET << std::endl; 
    for (j = 0; j < tmp; j++)
	{
		std::cout << YELLOW << std::setw(10) << j << "|" << RESET;
		std::cout << YELLOW << std::setw(10) <<  truncate(Contacts[j].GetFirstName()) << "|" << RESET;
		std::cout << YELLOW << std::setw(10) <<  truncate(Contacts[j].GetLastName()) << "|" << RESET;
		std::cout << YELLOW << std::setw(10) <<  truncate(Contacts[j].GetNickname()) << "|" << RESET;
		std::cout << YELLOW << std::endl << RESET;
	}
	while (1)
	{
		std::cout << "Please enter the index of the contact to display" << std::endl;
		getline(std::cin, to_display);
		if (std::cin.eof())
            return ;
		if (index_to_display(to_display) == -1)
			std::cout << RED << "Error ! Please enter a valid index !" << RESET << std::endl;
		else
		{
			index = index_to_display(to_display);
			break ;
		}		
	}
	std::cout << YELLOW << "First name : " <<  Contacts[index].GetFirstName() << RESET << std::endl;
	std::cout << YELLOW << "Last name : " <<  Contacts[index].GetLastName() << RESET << std::endl;
	std::cout << YELLOW << "Nickname : " <<  Contacts[index].GetNickname() << RESET << std::endl;
	std::cout << YELLOW << "Phone number : " <<  Contacts[index].GetPhoneNumber() << RESET << std::endl;
	std::cout << YELLOW << "Darkest secret : " <<  Contacts[index].GetDarkestSecret() << RESET << std::endl;
}