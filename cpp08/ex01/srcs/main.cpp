/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:07:43 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/10 19:53:36 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() 
{
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << IBLUE << "Shortest span is : " << BMAGENTA <<sp.shortestSpan() << RESET << std::endl << std::endl;
	std::cout << IBLUE << "Longest span is : " << BMAGENTA <<sp.longestSpan() << RESET << std::endl << std::endl;
	//--------------------------------------------------//
	Span random = Span(10000);
	
	std::cout << CYELLOW << "Filling vector with N random number :" << RESET << std::endl << std::endl;

	random.fillingWithRandomNumber();

	std::cout << ICYAN << "Shortest span is : " << BMAGENTA <<random.shortestSpan() << RESET << std::endl << std::endl;
	std::cout << ICYAN << "Longest span is : " << BMAGENTA <<random.longestSpan() << RESET << std::endl;
	return 0;
}
// 2147483647