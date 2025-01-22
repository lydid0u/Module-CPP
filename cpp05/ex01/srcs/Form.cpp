#include "Form.hpp"

Form::beSigned(Bureaucrat &instance_bureaucrat) {
    if (this->_signed == false)
    {
        this->_signed == true;
        std::cout << "Form has been signed !" << std::endl;
    }
    else
        std::cout << "Form is already signed !" << std::endl;
}

Form::signForm() {
    if (_signed == false)
        std::cout << getName() << " couldn't sign because the form hasn't " << std::endl;
    std::cout << getName() << " signed "
}