/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:36:23 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/30 18:30:39 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signGrade(150), _executeGrade(150)
{
    std::cout << "AForm Default constructor has been called" << std::endl;
	_isSigned = 0;
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
    std::cout << "AForm Constructor has been called" << std::endl;
	if (signGrade > 150) {
    	throw GradeTooLowException();
	}
	else if (signGrade < 1) {
		throw GradeTooHighException();
	}
	_isSigned = 0;
}

AForm::AForm(const AForm& other) :  _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	_isSigned = (other._isSigned);
	*this = other;
    std::cout << "AForm copy constructor called.\n";
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "Copy assignment operator called" << std::endl;
   	if (this != &other) 
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm(){
	std::cout << getName() << " has been destroyed." << std::endl;
}

std::string AForm::getName() const 
{
	return (_name);
}

int AForm::getSignedGrade() const {
	return (_signGrade);
}

int AForm::getExecuteGrade() const {
	return (_executeGrade);
}

bool AForm::getIsSigned() const {
	return (_isSigned);
}

const char *AForm::GradeTooHighException::what() const throw() 
{
    return ("Error - can't sign AForm : Grade too high\n");
}

const char *AForm::GradeTooLowException::what() const throw() 
{
    return ("Error - can't sign AForm : Grade too low\n");
}

const char *AForm::AlreadySignedException::what() const throw() 
{
    return ("Error : AForm already signed\n");
}

const char *AForm::NotSignedException::what() const throw() 
{
    return ("Error : AForm is not signed so you can't execute it\n");
}

void    AForm::beSigned(Bureaucrat &instance_bureaucrat) {
    if (instance_bureaucrat.getGrade() < this->_signGrade)
        this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form_instance) {
    out << form_instance.getName() << ", AForm grade " << form_instance.getSignedGrade() << " and is it signed : " << std::boolalpha << form_instance.getIsSigned();
    return out;
}
