/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:11:52 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/29 20:22:45 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Intern.hpp
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"


class Intern : public AForm {
public:
	Intern();
	Intern(const Intern &other);
	Intern& operator=(const Intern &other);
	~Intern();

	AForm *makeForm(std::string formName, std::string target);
};

#endif // Intern_HPP

#include "AForm.hpp"
