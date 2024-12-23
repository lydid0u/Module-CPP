/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 23:10:39 by lboudjel          #+#    #+#             */
/*   Updated: 2024/12/05 23:31:06 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : _type("WrongCat")
{
	std::cout << "Default WrongCat constructor has been created.\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    _type = other._type;
    std::cout << "WrongCat has been copied." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other) { 
        WrongAnimal::operator=(other); 
        _type = other._type;
    }
    std::cout << "WrongCat has been assigned." << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat has been destroyed.\n";
}

std::string WrongCat::getType() const
{
	return (_type);
}

void	WrongCat::makeSound() const
{
 	std::cout << GREEN << "wwooemm.\n" << RESET;
}