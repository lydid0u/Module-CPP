/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:48:59 by lboudjel          #+#    #+#             */
/*   Updated: 2024/12/05 23:20:09 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Default Animal constructor has been created.\n";
}

Animal::Animal(const Animal &other) {
    *this = other;
    std::cout << "Animal has been copied." << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        _type = other._type;
    }
    std::cout << "Animal has been assigned." << std::endl;
    return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal has been destroyed.\n";
}

std::string Animal::getType() const
{
	return (_type);
}

void	Animal::makeSound() const
{
	std::cout << BLUE << "Cette fonction fait le bruit d'un animal\n" << RESET;
}