/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:48:59 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/29 19:27:22 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Default Animal constructor has been created.\n";
}

Animal::~Animal()
{
	std::cout << "Animal has been destroyed.\n";
}


Cat::Cat() : _type("Cat")
{
	std::cout << "Default Cat constructor has been created.\n";
}

Cat::~Cat()
{
	std::cout << "Cat has been destroyed.\n";
}

std::string Animal::getType() const
{
	return (_type);
}

std::string Cat::getType() const
{
	return (_type);
}


void	Animal::makeSound() const
{
	std::cout << BLUE << "Cette fonction fait le bruit d'un animal\n" << RESET;
}


void	Cat::makeSound() const
{
	std::cout << GREEN << "meow.\n" << RESET;
}