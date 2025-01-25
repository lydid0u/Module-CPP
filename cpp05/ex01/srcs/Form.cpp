#include "Form.hpp"

std::string Form::getName() const {
	return (_name);
}

int Form::getSignedGrade() const {
	return (_signGrade);
}

bool Form::getIsSigned() const {
	return (_signed);
}



void    Form::beSigned(Bureaucrat &instance_bureaucrat) {
    if (this->_signed == false)
    {
        this->_signed == true;
        // signForm();
        std::cout << "Form has been signed !" << std::endl;
    }
    else
        std::cout << "Form is already signed !" << std::endl;
}



std::ostream &operator<<(std::ostream &out, const Form &form_instance) {
    // out << form_instance.getName() << ", form grade " << form_instance.getGrade() << " and is it signed : " << form_instance._signed;
    return out;
}