/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:11:52 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/30 17:36:13 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Intern.hpp
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern  {
public:
	Intern();
	Intern(const Intern &other);
	Intern& operator=(const Intern &other);
	~Intern();

	AForm *makeForm(std::string const &formName, std::string const &target);
};

#endif // Intern_HPP

#include "AForm.hpp"
