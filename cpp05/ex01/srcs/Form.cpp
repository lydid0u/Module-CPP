/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:36:23 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/30 17:00:11 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signGrade(150), _executeGrade(150)
{
	_isSigned = 0;
    std::cout << "Form Default constructor has been called" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
    std::cout << "Form Constructor has been called" << std::endl;
	if (signGrade > 150) {
    	throw GradeTooLowException();
	}
	else if (signGrade < 1) {
		throw GradeTooHighException();
	}
	_isSigned = 0;
}

Form::Form(const Form& other) :  _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	_isSigned = other._isSigned;
	*this = other;
    std::cout << "Form copy constructor called.\n";
}

Form& Form::operator=(const Form& other) 
{
	_isSigned = 0;
	std::cout << "Copy assignment operator called" << std::endl;
   	if (this != &other) 
        _isSigned = other._isSigned;
    return *this;
}

Form::~Form(){
	std::cout << getName() << " has been destroyed." << std::endl;
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
    return ("Error - can't sign form : Grade too high\n");
}

const char *Form::GradeTooLowException::what() const throw() 
{
    return ("Error - can't sign form : Grade too low\n");
}

const char *Form::AlreadySignedException::what() const throw() 
{
    return ("Error : Form already signed\n");
}

void    Form::beSigned(Bureaucrat &instance_bureaucrat) {
    if (instance_bureaucrat.getGrade() < this->_signGrade)
        this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form_instance) {
    out << form_instance.getName() << ", form grade " << form_instance.getSignedGrade() << " and is it signed : " << std::boolalpha << form_instance.getIsSigned();
    return out;
}
