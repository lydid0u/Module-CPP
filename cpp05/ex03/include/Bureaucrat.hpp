/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:09:08 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/30 16:00:26 by lboudjel         ###   ########.fr       */
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
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BLACK   "\033[30m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"
#define REVERSED "\033[7m"
#define GREY    "\033[90m"
#define LIGHT_RED "\033[91m"
#define LIGHT_GREEN "\033[92m"
#define LIGHT_YELLOW "\033[93m"
#define LIGHT_BLUE "\033[94m"
#define LIGHT_MAGENTA "\033[95m"
#define LIGHT_CYAN "\033[96m"
#define LIGHT_WHITE "\033[97m"

class AForm;

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

    void        signForm(AForm &instance_form);
    void        executeForm(AForm const & form);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };


private:
	const std::string _name;
	int	_grade;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat_instance);

#endif // Bureaucrat_HPP