/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:07:43 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/29 19:57:04 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int	main(void)
{
	try
	{
		Bureaucrat Sirine("Sirine", 137);
		Bureaucrat Adnan("Adnan", 26);
		Bureaucrat Moha("Moha", 1);
        
		ShrubberyCreationForm Shrub("Shrub");
		RobotomyRequestForm Robot("Wall-E");
		PresidentialPardonForm President("Macron");
        
        std::cout << std::endl;

        //         Shrubbery        //
        try
        {
            Sirine.signForm(Shrub);
		    Sirine.executeForm(Shrub);
        }
        catch(const std::exception& e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }

        //         Robotomy        //
        try
        {
            Moha.signForm(Robot);
		    Moha.executeForm(Robot);
        }
        catch(const std::exception& e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
        
        //         President        //
        try
        {
            Moha.signForm(President);
		    Moha.executeForm(President);
        }
        catch(const std::exception& e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	return(0);
}
