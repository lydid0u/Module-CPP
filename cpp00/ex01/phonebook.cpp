#include "PhoneBook.hpp"

    PhoneBook phonebook;



void add()
{
    if (phonebook.i < 8)
    {
        std::cout << "Please enter first name :" << std::endl;
        getline(std::cin, phonebook.Contacts[phonebook.i].FirstName);
        std::cout << "Please enter last name :" << std::endl;
        getline(std::cin, phonebook.Contacts[phonebook.i].LastName);
        std::cout << "Please enter Nickname :" << std::endl;
        getline(std::cin, phonebook.Contacts[phonebook.i].Nickname);
        std::cout << "Please enter your phone number :" << std::endl;
        getline(std::cin, phonebook.Contacts[phonebook.i].PhoneNumber);
        std::cout << "Please tell me your darkest secret :" << std::endl;
        getline(std::cin, phonebook.Contacts[phonebook.i].DarkestSecret);
    }
    else
    {
        std::cout << "Please enter first name :" << std::endl;
        getline(std::cin, phonebook.Contacts[8].FirstName);
        std::cout << "Please enter last name :" << std::endl;
        getline(std::cin, phonebook.Contacts[8].LastName);
        std::cout << "Please enter Nickname :" << std::endl;
        getline(std::cin, phonebook.Contacts[8].Nickname);
        std::cout << "Please enter your phone number :" << std::endl;
        getline(std::cin, phonebook.Contacts[8].PhoneNumber);
        std::cout << "Please tell me your darkest secret :" << std::endl;
        getline(std::cin, phonebook.Contacts[8].DarkestSecret);
    }
    phonebook.i++;
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
        return str; // Retourner la chaîne originale si elle est assez courte
}

void search()
{  
    int index;

    std::cout << std::right;
    std::cout << std::setw(11) << "index|" << std::setw(11) << "first name|" << std::setw(11) << "last name|" << std::setw(11) << "nickname|" << std::endl; 
    for (int i = 0; i < phonebook.i; i++)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) <<  truncate(phonebook.Contacts[i].FirstName) << "|";
        std::cout << std::setw(10) <<  truncate(phonebook.Contacts[i].LastName) << "|";
        std::cout << std::setw(10) <<  truncate(phonebook.Contacts[i].Nickname) << "|";
        std::cout << std::endl;
    }
    std::string to_display;
    while (1)
    {
        std::cout << "Please enter the index of the contact to display" << std::endl;
        getline(std::cin, to_display);
        if (index_to_display(to_display) == -1)
            std::cout << "Error ! Please enter a valid index !" << std::endl;
        else
        {
            index = index_to_display(to_display);
            break ;
        }        

    }
    std::cout << "First name : " <<  phonebook.Contacts[index].FirstName << std::endl;
    std::cout << "Last name : " <<  phonebook.Contacts[index].LastName << std::endl;
    std::cout << "Nickname : " <<  phonebook.Contacts[index].Nickname << std::endl;
    std::cout << "Phone number : " <<  phonebook.Contacts[index].PhoneNumber << std::endl;
    std::cout << "Darkest secret : " <<  phonebook.Contacts[index].DarkestSecret << std::endl;
}


int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    while (1)
    {
        std::cout << "Hello, please enter a command :" << std::endl;
        std::string command;
        getline(std::cin, command);
        if (command == "ADD")
            add();
        else if (command == "SEARCH")
            search();
        else if (command == "EXIT")
            exit (0);
        else
            std::cout << "Error, command is not valid !" << std::endl;
    }
}