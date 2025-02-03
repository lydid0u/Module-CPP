/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:07:43 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/30 17:01:07 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main() 
{
	try {
		Bureaucrat Bureau("Lydia", 150);
		
		std::cout << "\n-----Checking << operator-----\n";
		std::cout << GREEN << Bureau << RESET << std::endl << std::endl;
	
		try {
			Bureau.setGrade(149);
		}
		catch (const std::exception &e) {
			std::cerr << "Erreur : " << e.what() << std::endl;
		}
		
		std::cout << "-----Working incrementing and decrementing-----\n" << BLUE;
		
		Bureau.increment();
		Bureau.decrement();
		
		std::cout << RESET << "-----Failing incrementing and decrementing-----\n" << RED;
	
		Bureau.setGrade(150);
		Bureau.decrement();
	
		Bureau.setGrade(1);
		Bureau.increment();
	
		std::cout << RESET << "-----Failing : grade too high and too low-----\n" << RED;
	
    	try {
    	    Bureau.setGrade(-5);
    	}
    	catch(std::exception const& error) {
    	    std::cout << error.what() << std::endl;
    	}
		
		try {
    		Bureau.setGrade(151);
    	}
    	catch(std::exception const& error) {
    	    std::cout << error.what() << RESET << std::endl;
    	}
		}
	catch (const std::exception &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
		return 1;
	}

    return 0;
}