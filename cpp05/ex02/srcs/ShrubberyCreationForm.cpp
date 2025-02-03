/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:58:02 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/30 17:49:06 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Someone")
{
	std::cout << "Shrubbery Default constructor has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Shrubbery Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {
	*this = other;
    std::cout << "Shrubbery copy constructor called.\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Shrubbery Copy assignment operator called" << std::endl;
   	if (this != &other) 
        _target = other._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery Destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	std::ofstream 	file_tree((_target + "_shrubbery").c_str());
	if (file_tree.is_open()) 
	{
    	std::cout << BLUE << "File_tree has been created ! " << RESET << std::endl;
		file_tree << "        *        " << std::endl;
    	file_tree << "       ***       " << std::endl;
    	file_tree << "      *****      " << std::endl;
    	file_tree << "     *******     " << std::endl;
    	file_tree << "    *********    " << std::endl;
    	file_tree << "   ***********   " << std::endl;
    	file_tree << "  *****$*****$*  " << std::endl;
    	file_tree << " *****$***$***** " << std::endl;
    	file_tree << "       |||       " << std::endl;
    	file_tree << "       |||       " << std::endl;
    	file_tree << "       |||       " << std::endl;
	}
	else
		std::cerr << "An error occured while creating the file_tree." << std::endl;
}






