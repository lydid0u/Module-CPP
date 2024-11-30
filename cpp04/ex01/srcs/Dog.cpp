/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:47:48 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/30 00:50:30 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : _type("Dog")
{
	cerveau = new Brain();
	std::cout << "Default Dog constructor has been created.\n";
}

Dog::Dog(const Dog& other) {
	cerveau = new Brain(*other.cerveau); //ici deep copy
    std::cout << "Dog copy constructor called.\n";
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Copy assignment operator called" << std::endl;
   	if (this != &other) 
   {
        _type = other._type;
        if (cerveau) {
            delete cerveau;
        }
        cerveau = new Brain(*other.cerveau);
    }
    return *this;
}

Dog::~Dog() {
	delete cerveau;
	std::cout << "Dog destructor called" << std::endl;
}

std::string Dog::getType() const
{
	return (_type);
}

void	Dog::makeSound() const
{
	std::cout << BLUE << "wouaf woUAF.\n" << RESET;
}