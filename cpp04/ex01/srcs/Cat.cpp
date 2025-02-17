/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:28:48 by lboudjel          #+#    #+#             */
/*   Updated: 2024/12/23 16:08:24 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Cat.cpp
#include "Cat.hpp"

Cat::Cat() : _type("Cat")
{
	cerveau = new Brain();
	std::cout << "Default Cat constructor has been created.\n";
}

Cat::Cat(const Cat& other) {
	cerveau = new Brain(*other.cerveau); //ici deep copy
    std::cout << "Cat copy constructor called.\n";
}

Cat& Cat::operator=(const Cat& other) {
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

Cat::~Cat() {
	delete cerveau;
	std::cout << "Cat destructor called" << std::endl;
}

std::string Cat::getType() const
{
	return (_type);
}

void	Cat::makeSound() const
{
	std::cout << GREEN << "meow.\n" << RESET;
}

void Cat::setBrainIdea(int n, std::string idea) {
	if (cerveau)
		cerveau->setIdea(n, idea);
}

std::string Cat::getBrainIdea(int n) const 
{
	if (cerveau)
		return cerveau->getIdea(n);
	return "";
}