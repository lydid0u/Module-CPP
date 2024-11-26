/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:48:59 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/26 23:59:53 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default Animal constructor has been created.\n";
}

Animal::~Animal()
{
	std::cout << "Animal has been destroyed.\n";
}

Dog::Dog()
{
	std::cout << "Default Dog constructor has been created.\n";
}

Dog::~Dog()
{
	std::cout << "Dog has been destroyed.\n";
}

Cat::Cat()
{
	std::cout << "Default Cat constructor has been created.\n";
}

Cat::~Cat()
{
	std::cout << "Cat has been destroyed.\n";
}

// Dog::Dog(std::string ) : Animal(name)