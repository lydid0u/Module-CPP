/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   PhoneBook.hpp									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/15 15:38:01 by lboudjel		  #+#	#+#			 */
/*   Updated: 2024/10/16 18:43:44 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "Contact.hpp"


#define RESET   "\033[0m"
#define RED	 "\033[31m"
#define BLUE	"\033[34m" 
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m" 

class PhoneBook
{
	public:
	PhoneBook(void);
	~PhoneBook(void);
	void add();
	void search();
	
	private:
	Contact Contacts[8];
	int i;
	int eight;
	void	EighthContact();
	int	index_to_display(std::string to_display);
	int	check_name(std::string str);
	int	check_nickname(std::string str);
	int	check_number(std::string str);
};

#endif