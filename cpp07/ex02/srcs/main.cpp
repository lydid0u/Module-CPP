/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:47:35 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/05 17:00:01 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"

int	main()
{
	try {
		Array<std::string> emptyArray;
		std::cout << GREEN << "Size of empty array : " << emptyArray.size() << RESET << std::endl << std::endl;
        
        // std::cout << empty[0] << std::endl;
        
		Array<int> intArray(5);
		std::cout << BLUE << "Size of intArray : " << intArray.size() << RESET << std::endl;
		for (unsigned int i = 0; i < intArray.size(); i++)
		{
			intArray[i] = i;
			std::cout << "[" << i << "] : " << intArray[i] << std::endl;
		}
        std::cout << std::endl;
        
		Array<int> copyArray = intArray;
		copyArray[0] = 42;
        copyArray[3] = -42;

		std::cout << BLUE << "Size of  copyArray: " << copyArray.size() << RESET << std::endl;
        for (unsigned int i = 0; i < copyArray.size(); i++)
		{
			intArray[i] = i;
			std::cout << "[" << i << "] : " << copyArray[i] << std::endl;
		}
        std::cout << std::endl;
		try {
            std::cout << RED << "Trying index out of range :" << RESET << std::endl;
            copyArray[-1];
            // copyArray[6];
        }
        catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
        std::cout << std::endl;

	}
	catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}