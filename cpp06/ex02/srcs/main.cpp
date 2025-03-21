/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:07:43 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/04 16:09:24 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ABC.hpp"

//on genere au hasard une class avec generate() quon return dans base_abc
//la 1e fonction prend un pointeur et peut etre nul, la 2e une reference
int main() 
{
	Base *base_abc = generate();

	std::cout << BLUE << "Function with pointer :\n" << RESET;
	identify(base_abc);

	std::cout << BLUE << "Function with reference :\n" << RESET;
	identify(*base_abc);

	delete base_abc;
	return (0);
}