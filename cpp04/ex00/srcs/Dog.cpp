/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:47:48 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/29 19:27:24 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Dog::Dog() : _type("Dog")
{
	std::cout << "Default Dog constructor has been created.\n";
}

Dog::~Dog()
{
	std::cout << "Dog has been destroyed.\n";
}

void	Dog::makeSound() const
{
	std::cout << RED << "wouaf wOUAF.\n" << RESET;
}

std::string Dog::getType() const
{
	return (_type);
}

