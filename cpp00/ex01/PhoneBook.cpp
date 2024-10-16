#include "PhoneBook.hpp"
#include <stdio.h>

    PhoneBook phonebook;

int    check_name(std::string str)
{
    for (unsigned long i = 0; i < str.length(); i++)
    {
        if (!isalpha(str[i]))
            return (1);
    }
    return (0);
}

int    check_nickname(std::string str)
{
    for (unsigned long i = 0; i < str.length(); i++)
    {
        if (!isalnum(str[i]))
            return (1);
    }
    return (0);
}

int    check_number(std::string str)
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

void eighth_contact()
{
    std::string str;

    std::cout << "Please enter first name :" << std::endl;
    getline(std::cin, str);
    if (!check_name(str))
        phonebook.Contacts[3].FirstName = str;
    else
    {
        std::cout << RED << "Error a character is incorrect :(" << RESET << std::endl;
        return ;
    }
    std::cout << "Please enter last name :" << std::endl;
    getline(std::cin, str);
    if (!check_name(str))
        phonebook.Contacts[3].LastName = str;
    else
    {
        std::cout << RED << "Error a character is incorrect :(" << RESET << std::endl;
        return ;
    }
    std::cout << "Please enter Nickname :" << std::endl;
    getline(std::cin, str);
    if (!check_nickname(str))
        phonebook.Contacts[3].Nickname = str;
    else
    {
        std::cout << RED << "Error a character is incorrect :(" << RESET << std::endl;
        return ;
    }
    std::cout << "Please enter your phone number :" << std::endl;
    getline(std::cin, str);
    if (!check_number(str) || str[0] == '*')
        phonebook.Contacts[3].PhoneNumber = str;
    else
    {
        std::cout << RED << "Please enter a valid phone number (starting with 0 and 10 digits)" << RESET << std::endl;
        return ;
    }
    std::cout << "Please tell me your darkest secret :" << std::endl;
    getline(std::cin, phonebook.Contacts[3].DarkestSecret);
    // phonebook.i = 3;
}

void add()
{
    std::string str;
    if (phonebook.i <= 2)
    {
        std::cout << "Please enter first name :" << std::endl;
        getline(std::cin, str);
        if (!check_name(str))
            phonebook.Contacts[phonebook.i].FirstName = str;
        else
        {
            std::cout << RED << "Error a character is incorrect :(" << RESET << std::endl;
            return ;
        }
        std::cout << "Please enter last name :" << std::endl;
        getline(std::cin, str);
        if (!check_name(str))
            phonebook.Contacts[phonebook.i].LastName = str;
        else
        {
            std::cout << RED << "Error a character is incorrect :(" << RESET << std::endl;
            return ;
        }
        std::cout << "Please enter Nickname :" << std::endl;
        getline(std::cin, str);
        if (!check_nickname(str))
            phonebook.Contacts[phonebook.i].Nickname = str;
        else
        {
            std::cout << RED << "Error a character is incorrect :(" << RESET << std::endl;
            return ;
        }
        std::cout << "Please enter your phone number :" << std::endl;
        getline(std::cin, str);
        if (!check_number(str) || str[0] == '*')
            phonebook.Contacts[phonebook.i].PhoneNumber = str;
        else
        {
            std::cout << RED << "Please enter a valid phone number (starting with 0 and 10 digits)" << RESET << std::endl;
            return ;
        }
        std::cout << "Please tell me your darkest secret :" << std::endl;
        getline(std::cin, phonebook.Contacts[phonebook.i].DarkestSecret);
        phonebook.i++;
    }
    else
        eighth_contact();
}

int index_to_display(std::string to_display)
{   
    if (isdigit(to_display[0]) && to_display.length() == 1)
    {
        if (to_display[0] - '0' > phonebook.i)
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

void search()
{  
    int index;

    std::cout << std::right;
    std::cout << std::setw(11) << "index|" << std::setw(11) << "first name|" << std::setw(11) << "last name|" << std::setw(11) << "nickname|" << std::endl; 
    for (int i = 1; i <= phonebook.i; i++)
    {
        std::cout << YELLOW << std::setw(10) << i << "|" << RESET;
        std::cout << YELLOW << std::setw(10) <<  truncate(phonebook.Contacts[i].FirstName) << "|" << RESET;
        std::cout << YELLOW << std::setw(10) <<  truncate(phonebook.Contacts[i].LastName) << "|" << RESET;
        std::cout << YELLOW << std::setw(10) <<  truncate(phonebook.Contacts[i].Nickname) << "|" << RESET;
        std::cout << YELLOW << std::endl << RESET;
    }
    std::string to_display;
    while (1)
    {
        std::cout << "Please enter the index of the contact to display" << std::endl;
        getline(std::cin, to_display);
        if (index_to_display(to_display) == -1)
            std::cout << RED << "Error ! Please enter a valid index !" << RESET << std::endl;
        else
        {
            index = index_to_display(to_display);
            break ;
        }        

    }
    std::cout << YELLOW << "First name : " <<  phonebook.Contacts[index].FirstName << RESET << std::endl;
    std::cout << YELLOW << "Last name : " <<  phonebook.Contacts[index].LastName << RESET << std::endl;
    std::cout << YELLOW << "Nickname : " <<  phonebook.Contacts[index].Nickname << RESET << std::endl;
    std::cout << YELLOW << "Phone number : " <<  phonebook.Contacts[index].PhoneNumber << RESET << std::endl;
    std::cout << YELLOW << "Darkest secret : " <<  phonebook.Contacts[index].DarkestSecret << RESET << std::endl;
}


int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    while (1)
    {
        std::cout << BLUE << "Hello, please enter a command :" << RESET << std::endl;
        std::string command;
        getline(std::cin, command);
        if (command == "ADD")
            add();
        else if (command == "SEARCH")
            search();
        else if (command == "EXIT")
            exit (0);
        else
            std::cout << RED << "Error, command is not valid !" << RESET << std::endl;
    }
}
