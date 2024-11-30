/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:28:48 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/29 21:55:57 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Cat.cpp
#include "Cat.hpp"

Cat::Cat() : _type("Cat")
{
	cerveau = new Brain();
	std::cout << "Default Cat constructor has been created.\n";
}

// Cat::Cat(const Cat& other) {
// 	std::cout << "Copy constructor called" << std::endl;
// 	// Add copy logic here, e.g., memberVariable = other.memberVariable;
// }

// Cat& Cat::operator=(const Cat& other) {
// 	std::cout << "Copy assignment operator called" << std::endl;
// 	if (this != &other) {
// 		// Add assignment logic here, e.g., memberVariable = other.memberVariable;
// 	}
// 	return *this;
// }

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