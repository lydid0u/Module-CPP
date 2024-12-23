/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:47:48 by lboudjel          #+#    #+#             */
/*   Updated: 2024/12/05 23:20:35 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : _type("Dog")
{
	std::cout << "Default Dog constructor has been created.\n";
}

Dog::Dog(const Dog &other) : Animal(other) {
    _type = other._type;
    std::cout << "Dog has been copied." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) { 
        Animal::operator=(other); 
        _type = other._type;
    }
    std::cout << "Dog has been assigned." << std::endl;
    return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog has been destroyed.\n";
}

std::string Dog::getType() const
{
	return (_type);
}

void	Dog::makeSound() const
{
	std::cout << RED << "wouaf wOUAF.\n" << RESET;
}