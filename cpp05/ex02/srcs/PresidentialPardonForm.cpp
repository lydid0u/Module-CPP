/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:38:09 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/30 17:48:40 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Someone")
{
	std::cout << "President Default constructor has been called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "President Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
	*this = other;
    std::cout << "President copy constructor called.\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "President Copy assignment operator called" << std::endl;
   	if (this != &other) 
        _target = other._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "President Destructor called" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();	
	else
		std::cout << YELLOW << "Informs that " << _target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}






