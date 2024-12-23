/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:10:13 by lboudjel          #+#    #+#             */
/*   Updated: 2024/12/05 23:20:35 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : _type("Cat")
{
	std::cout << "Default Cat constructor has been created.\n";
}

Cat::Cat(const Cat &other) : Animal(other) {
    _type = other._type;
    std::cout << "Cat has been copied." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) { 
        Animal::operator=(other); 
        _type = other._type;
    }
    std::cout << "Cat has been assigned." << std::endl;
    return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat has been destroyed.\n";
}

std::string Cat::getType() const
{
	return (_type);
}

void	Cat::makeSound() const
{
	std::cout << GREEN << "meow.\n" << RESET;
}