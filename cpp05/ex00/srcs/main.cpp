/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:07:43 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/21 23:37:30 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main() 
{
	std::cout << BLUE;

	Bureaucrat Bureau("Lydia", 15);
	// Bureau.setGrade(15);

	std::cout << RED << "\n" << Bureau << BLUE << std::endl << std::endl;

	try {
		int digit = Bureau.getGrade();
    	if (digit > 150) {
        	throw GradeTooLowException("Grade too low, please stay between 1 and 150.\n");
	    }
		else if (digit < 1) {
			throw GradeTooHighException("Grade too high, please stay between 1 and 150.\n");
		}
			std::cout << "Bureaucrat " << Bureau.getName() << " grade is valid: " << digit << std::endl << std::endl;
	}
	catch (const GradeTooLowException &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
		catch (const GradeTooHighException &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	Bureau.increment();
	std::cout << "Verifying grade post incrementation : " << Bureau.getGrade() << std::endl << std::endl;

	Bureau.decrement();
	std::cout << "Verifying grade post decrementation : " << Bureau.getGrade() << std::endl << std::endl;

	Bureau.setGrade(150);
	Bureau.decrement();

	Bureau.setGrade(1);
	Bureau.increment();

//-----------------------------------------------------------------------------------------------------//
	std::cout << YELLOW;

	Bureaucrat Crat("Adnan", -5);

	try {
	int digit = Crat.getGrade();
    if (digit > 150) {
    	throw GradeTooLowException("Grade too low, please stay between 1 and 150.\n");
    }
	else if (digit < 1) {
		throw GradeTooHighException("Grade too high, please stay between 1 and 150.\n");
	}
	std::cout << "Bureaucrat: " << Crat.getName() << " grade is valid: " << digit << std::endl << std::endl;
	}
	catch (const GradeTooLowException &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
		catch (const GradeTooHighException &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

//-----------------------------------------------------------------------------------------------------//
	std::cout << GREEN;

	Bureaucrat Buro("Saber", 158);

	try {
		int digit = Buro.getGrade();
    	if (digit > 150) {
        	throw GradeTooLowException("Grade too low, please stay between 1 and 150.\n");
	    }
		else if (digit < 1) {
			throw GradeTooHighException("Grade too high, please stay between 1 and 150.\n");
		}
		std::cout << "Bureaucrat " << Buro.getName() << " grade is valid: " << digit << std::endl << std::endl;
	}
	catch (const GradeTooLowException &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	catch (const GradeTooHighException &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	std::cout << RESET;

    return 0;
}