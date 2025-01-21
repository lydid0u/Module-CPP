/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:09:08 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/21 23:36:52 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception> 

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	// ~Bureaucrat();

	void		setName(std::string);
	std::string getName();
	void		setGrade(int grade);
	int 		getGrade();

	int			checkGrade();
private:
	std::string _name;
	int	_grade;
};

class GradeTooLowException : public std::exception {
public:
    explicit GradeTooLowException(const std::string& msg) : _errorMessage(msg) {}
    
    virtual ~GradeTooLowException() throw() {}

    // Méthode what() renvoyant le Message d'erreur
    virtual const char* what() const throw() {
        return _errorMessage.c_str();
    }

private:
    std::string _errorMessage;
};

class GradeTooHighException : public std::exception {
public:
    explicit GradeTooHighException(const std::string& msg) : _errorMessage(msg) {}
    
    virtual ~GradeTooHighException() throw() {}

    virtual const char* what() const throw() {
        return _errorMessage.c_str();
    }

private:
    std::string _errorMessage;
};

// std::ostream	&operator<<(std::ostream &out, const Fixed &value);

#endif // Bureaucrat_HPP