/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:36:23 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/25 19:31:22 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signGrade(150), _executeGrade(150)
{
    std::cout << "Form Default constructor has been called" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
    std::cout << "Form Constructor has been called" << std::endl;
}

Form::Form(const Form& other) :  _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	*this = other;
    std::cout << "Form copy constructor called.\n";
}

Form& Form::operator=(const Form& other) {
	std::cout << "Copy assignment operator called" << std::endl;
   	if (this != &other) 
        _isSigned = other._isSigned;
    return *this;
}

std::string Form::getName() const 
{
	return (_name);
}

int Form::getSignedGrade() const {
	return (_signGrade);
}

bool Form::getIsSigned() const {
	return (_isSigned);
}

const char *Form::GradeTooHighException::what() const throw() 
{
    return ("Error Form : Grade too high\n");
}

const char *Form::GradeTooLowException::what() const throw() 
{
    return ("Error Form : Grade too low\n");
}

void    Form::beSigned(Bureaucrat &instance_bureaucrat) {
    if (this->_isSigned == false)
    {
        this->_isSigned = true;
        // signForm();
        std::cout << "Form has been signed !" << std::endl;
    }
    else
        std::cout << "Form is already signed !" << std::endl;
}

// std::ostream &operator<<(std::ostream &out, const Form &form_instance) {
//     out << form_instance.getName() << ", form grade " << form_instance.getGrade() << " and is it signed : " << form_instance._isSigned;
//     return out;
// }

//dans les cnstructeurs bien proteger avec les throw