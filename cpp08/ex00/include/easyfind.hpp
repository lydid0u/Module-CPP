/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:09:08 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/08 18:21:36 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include "colors.hpp"

//doit trouver la 1e fois que i apparait dans param
//si rien est trouve, soit throw, soit return une valeur d'erreur de mon choix
template <typename T>
void	easyfind(T container, int toFind) { 
	try {
		typename T::iterator	it;
		
		it = std::find(container.begin(), container.end(), toFind);
		if (it == container.end())
			throw std::out_of_range("Did not find the integer ");
		else {
			size_t i = std::distance(container.begin(), it);
			std::cout << "Found " << toFind << " in position [" << BBLUE << i << RESET <<  "]" << std::endl;
			return ;
		}
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << BBLUE << toFind << RESET << std::endl;
	}
}

#endif