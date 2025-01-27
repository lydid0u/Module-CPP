/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:36:29 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/27 16:46:08 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
public:
	Form();
    Form(std::string name, int signGrade, int executeGrade);
    Form(const Form &src);
    Form &operator=(const Form &rhs);
	~Form();

	std::string getName() const ;
	int 		getSignedGrade() const ;
    bool        getIsSigned() const;

    void        beSigned(Bureaucrat &instance_bureaucrat);

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class AlreadySignedException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
private:
	const std::string _name;
	bool	_isSigned;
    const int     _signGrade;
    const int     _executeGrade;

};

std::ostream	&operator<<(std::ostream &out, const Form &form_instance);


#endif