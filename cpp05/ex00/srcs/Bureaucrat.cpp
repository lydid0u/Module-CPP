/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:08:08 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/21 23:24:33 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::string Bureaucrat::getName(){
	return (_name);
}

void	Bureaucrat::setName(std::string name){
	_name = name;
}

int Bureaucrat::getGrade(){
	return (_grade);
}

void	Bureaucrat::setGrade(int grade){
	_grade = grade;
}


// std::ostream &operator<<(std::ostream &out, const Fixed &value){
// 	out << value.toFloat();
// 	return out;
// }


// virtual const char* SmallerException::what() const throw()
// {
//     return _errorMessage.c_str();
// }