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

#define RESET   "\033[0m"
#define RED	 "\033[31m"
#define BLUE	"\033[34m" 
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m" 

class Bureaucrat {
public:
	Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();

	std::string getName() const ;
	void		setGrade(int grade);
	int 		getGrade() const ;

	void			increment();
	void			decrement();

private:
	const std::string _name;
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

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat_instance);

#endif // Bureaucrat_HPP