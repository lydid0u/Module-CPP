/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:09:08 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/06 19:38:12 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <vector>
#include <set>

#define RESET   "\033[0m"
#define RED	 "\033[31m"
#define BLUE	"\033[34m" 
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m" 

//doit trouver la 1e fois que i apparait dans param
//si rien est trouve, soit throw, soit return une valeur d'erreur de mon choix
template <typename T>
void	easyfind(T container, int toFind) { 
	try {
		for (size_t i = 0; i < container.size(); i++)
		{
				if (toFind == container[i])
				{
					std::cout << "Found " << toFind << " in position [" << BLUE << i << RESET << "]\n";
					return;
				}
		}
		throw std::out_of_range("Did not find the integer ");
	}
	catch (std::exception& e) {
		std::cout << RED << "Error: " << e.what() << toFind << RESET << std::endl;
	}
}

#endif