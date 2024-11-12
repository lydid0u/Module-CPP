/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:07:50 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/08 16:11:05 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	// std::cout << std::boolalpha << (a == b) << std::endl;
	// std::cout << std::boolalpha << (a != b) << std::endl;
	// std::cout << std::boolalpha << (a >= b) << std::endl;
	
	std::cout << Fixed::max(a, b) << std::endl;
	
	std::cout << Fixed::max(a, b) << std::endl;
	
	return 0;
}