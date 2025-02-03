/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:36:29 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/30 16:39:39 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class AForm {
public:
	AForm();
    AForm(std::string name, int signGrade, int executeGrade);
    AForm(const AForm &src);
    AForm &operator=(const AForm &rhs);
	~AForm();

	std::string getName() const ;
	int 		getSignedGrade() const ;
    int 		getExecuteGrade() const ;
    bool        getIsSigned() const;

    void        beSigned(Bureaucrat &instance_bureaucrat);
    virtual void		execute(Bureaucrat const &executor) const = 0;
    
    //throw
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
    class NotSignedException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    
private:
	const std::string _name;
	bool	_isSigned;
    const int     _signGrade;
    const int     _executeGrade;

};

std::ostream	&operator<<(std::ostream &out, const AForm &form_instance);


#endif