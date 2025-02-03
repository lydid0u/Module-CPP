/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:46:08 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/30 17:48:03 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	try
	{
		Bureaucrat Ocea("Ocea", 1);
		Intern someRandomIntern;
		std::cout << std::endl;
		std::cout << "Intern :" << std::endl;
		AForm *rrf = someRandomIntern.makeForm("shrubbery creation", "NORAAA");
		std::cout << std::endl;
		if (!rrf)
			return 1;
		Ocea.signForm(*rrf);
		Ocea.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	return(0);
}
