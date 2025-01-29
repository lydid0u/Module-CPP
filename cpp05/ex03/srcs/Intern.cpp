/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:14:53 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/29 20:23:06 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default constructor has been called" << std::endl;
}

Intern::Intern(const Intern& other) {
	*this = other;
    std::cout << "Intern copy constructor called.\n";
}

Intern& Intern::operator=(const Intern &other) 
{
	std::cout << "Intern Copy assignment operator called" << std::endl;
    if (this != &other)
        return *this;
	else
		return *this;
}

Intern::~Intern() {
	std::cout << "Intern Destructor called" << std::endl;
}