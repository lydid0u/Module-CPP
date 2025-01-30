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

Intern::Intern(const Intern& other)
{
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

AForm* createRobotomyRequest(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardon(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* createShrubberyCreation(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    const std::string formNames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };

    AForm* (*formCreators[])(std::string) = {
        createRobotomyRequest,
        createPresidentialPardon,
        createShrubberyCreation
    };

    for (int i = 0; i < 3; ++i) {
        if (formNames[i] == formName) {
            std::cout << GREEN << "Intern creates " << formName << " form." << RESET << std::endl;
            return formCreators[i](target);
        }
    }
    std::cout << RED << "Oops: [" << formName << "] unknown form name !" << RESET << std::endl;
    return NULL;
}
