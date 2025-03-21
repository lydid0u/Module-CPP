/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:08:08 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/21 23:24:33 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(1)
{
    std::cout << "Bureaucrat Default constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Bureaucrat Constructor has been called" << std::endl;
	if (grade > 150) {
    	throw GradeTooLowException();
	}
	else if (grade < 1) {
		throw GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	*this = other;
    std::cout << "Bureaucrat copy constructor called.\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Copy assignment operator called" << std::endl;
   	if (this != &other) 
        _grade = other.getGrade();
    return *this;
}

std::string Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

void	Bureaucrat::setGrade(int grade){
	if (grade > 150) {
    	throw GradeTooLowException();
	}
	else if (grade < 1) {
		throw GradeTooHighException();
	}
	else
		_grade = grade;
}

Bureaucrat::~Bureaucrat(){
	std::cout << getName() << " has been destroyed." << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() 
{
    return ("Bureaucrat : Grade too high\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() 
{
    return ("Bureaucrat : Grade too low\n");
}

void	Bureaucrat::decrement()
{
	try 
	{
		int grade = getGrade();
		setGrade(++grade);
		if (grade > 150) {
			throw GradeTooLowException();
		}
		std::cout << "Bureaucrat: " << getName() << " NEW grade is valid: " << getGrade() << std::endl << std::endl;
	}
	catch (const GradeTooLowException &e) {
		std::cerr << "Erreur : " << e.what() << std::endl; 
	}
}

void	Bureaucrat::increment()
{
	try 
	{
		int grade = getGrade();
		setGrade(--grade);
		if (grade < 1) {
			throw GradeTooHighException();
		}
		std::cout << "Bureaucrat: " << getName() << " NEW grade is valid: " << getGrade() << std::endl << std::endl;
	}
		catch (const GradeTooHighException &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
}

void    Bureaucrat::signForm(AForm &instance_form) {
    if (instance_form.getIsSigned() == true)
		throw AForm::AlreadySignedException();
	else if (getGrade() > instance_form.getSignedGrade())
		throw AForm::GradeTooLowException();
	else 
	{
		instance_form.beSigned(*this);
    	std::cout << getName() << " signed " << instance_form.getName() << " AForm" << std::endl;
	}
}

void	    Bureaucrat::executeForm(AForm const &instance_form)
{   
	if (instance_form.getIsSigned() == false)
		throw AForm::NotSignedException();
	else if (getGrade() > instance_form.getSignedGrade())
		throw AForm::GradeTooLowException();
	else 
	{
		instance_form.execute(*this);
		std::cout << getName() << " executed " << instance_form.getName() << std::endl << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat_instance) {
    out << bureaucrat_instance.getName() << ", bureaucrat grade " << bureaucrat_instance.getGrade() << ".";
    return out;
}