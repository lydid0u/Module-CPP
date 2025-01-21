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

#include "Bureaucrat.hpp"

int main() 
{
	Bureaucrat Bureau;
	Bureau.setName("Lydia");
	Bureau.setGrade(10);
	
	int digit = Bureau.getGrade();
    if (digit < 150) {
        throw GradeTooLowException("Grade too low, please stay between 1 and 150.\n");
    }
	else if (digit < 150) {
		throw GradeTooHighException("Grade too high, please stay between 1 and 150.\n");
	}
}
	
// //--------------------------
// 	Bureaucrat Crat;
// 	Crat.setName("Adnan");
// 	Crat.setGrade(-5);
	
// //--------------------------
// 	Bureaucrat Bc;
// 	Bc.setName("Saber");
// 	Bc.setGrade(158);

//     return 0;
// }