
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
public:
	Form();
    // Form(std::string name, int grade);
    Form(const Form &src);
    Form &operator=(const Form &rhs);
	~Form();

	std::string getName() const ;
	void		setGrade(int grade);
	int 		getGrade() const ;

    void        beSigned(Bureaucrat &instance_bureaucrat);
    void        signForm();

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
	bool	_signed;
    const int     _signGrade;
    const int     _executeGrade;

};

#endif