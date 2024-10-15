/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:38:01 by lboudjel          #+#    #+#             */
/*   Updated: 2024/10/15 15:43:54 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m" 
#define YELLOW  "\033[33m"

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