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
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(1)
{
    std::cout << "Bureaucrat Default constructor has been called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Bureaucrat Constructor has been called" << std::endl;
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
	_grade = grade;
}

Bureaucrat::~Bureaucrat(){
	std::cout << getName() << " has been destroyed." << std::endl;
}

void	Bureaucrat::decrement()
{
	try 
	{
		int grade = getGrade();
		setGrade(++grade);
		if (grade > 150) {
			throw GradeTooLowException("Grade too Low, can't decrement.\n");
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
			throw GradeTooHighException("Grade too high, can't decrement.\n");
		}
		std::cout << "Bureaucrat: " << getName() << " NEW grade is valid: " << getGrade() << std::endl << std::endl;
	}
		catch (const GradeTooHighException &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
}

void    Bureaucrat::signForm(Form &instance_form) {
    if (instance_form.getIsSigned() == false)
        std::cout << getName() << " couldn't sign " << instance_form.getName() << 
			" because the form is already signed." << std::endl;
    std::cout << getName() << " signed " << instance_form.getName();
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat_instance) {
    out << bureaucrat_instance.getName() << ", bureaucrat grade " << bureaucrat_instance.getGrade() << ".";
    return out;
}