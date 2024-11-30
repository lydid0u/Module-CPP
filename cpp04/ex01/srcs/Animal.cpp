/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:48:59 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/30 01:09:26 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Default Animal constructor has been created.\n";
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called\n";
}

std::string Animal::getType() const
{
	return (_type);
}

void	Animal::makeSound() const
{
	std::cout << BLUE << "Cette fonction fait le bruit d'un animal\n" << RESET;
}


