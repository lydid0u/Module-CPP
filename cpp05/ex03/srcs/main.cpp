/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:36:58 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/30 16:15:05 by lbarry           ###   ########.fr       */
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
		AForm *rrf = someRandomIntern.makeForm("robotomy request", "nora");
		std::cout << std::endl;
		if (!rrf)
			return 1;
		std::cout << "Name : " << rrf->getName() << std::endl;
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
