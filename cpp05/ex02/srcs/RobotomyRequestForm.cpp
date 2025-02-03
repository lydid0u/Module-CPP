/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:38:22 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/30 17:48:53 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Someone")
{
	std::cout << "Robotomy Default constructor has been called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Robotomy Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
	*this = other;
    std::cout << "Robotomy copy constructor called.\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "Robotomy Copy assignment operator called" << std::endl;
   	if (this != &other) 
        _target = other._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robotomy Destructor called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();	
	else
	{
		std::cout << BLUE << "*drill noises*" << RESET << std::endl;
		std::srand(std::time(0));
		if (std::rand() % 2 == 0)
			std::cout << GREEN << _target << " has been robotomized successfully" << RESET << std::endl;
		else
			std::cout << RED << "The robotomy of " << this->getName() << " has failed !" << RESET << std::endl;
	}
}






