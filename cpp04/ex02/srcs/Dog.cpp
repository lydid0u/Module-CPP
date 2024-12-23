/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:03:24 by lboudjel          #+#    #+#             */
/*   Updated: 2024/12/23 18:03:24 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : _type("Dog")
{
    cerveau = new Brain();
    std::cout << "Default Dog constructor has been created.\n";
}

Dog::Dog(const Dog& other) {
    cerveau = new Brain(*other.cerveau);
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

void Dog::makeSound() const
{
    std::cout << BLUE << "wouaf woUAF.\n" << RESET;
}

void Dog::setBrainIdea(int n, std::string idea) {
    if (cerveau)
        cerveau->setIdea(n, idea);
}

std::string Dog::getBrainIdea(int n) const {
    if (cerveau)
        return cerveau->getIdea(n);
    return "";
}
