/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.cpp										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/16 16:07:57 by lboudjel		  #+#	#+#			 */
/*   Updated: 2024/10/16 18:19:34 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <stdio.h>

int main()
{
	PhoneBook phonebook;
	std::string command;
	
	while (1)
	{
		std::cout << BLUE << "Hello, please enter a command :" << RESET << std::endl;
		getline(std::cin, command);
        if (std::cin.eof())
            return (1);
		if (command == "ADD" || command == "add")
			phonebook.add();
		else if (command == "SEARCH" || command == "search")
			phonebook.search();
		else if (command == "EXIT" || command == "exit")
			exit (0);
		else
			std::cout << RED << "Error, command is not valid !" << RESET << std::endl;
	}
}
