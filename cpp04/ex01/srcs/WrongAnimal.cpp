/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:16:19 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/29 19:16:15 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "Default WrongAnimal constructor has been created.\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal has been destroyed.\n";
}

WrongCat::WrongCat() : _type("WrongCat")
{
	std::cout << "Default WrongCat constructor has been created.\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat has been destroyed.\n";
}

std::string WrongAnimal::getType() const
{
	return (_type);
}

std::string WrongCat::getType() const
{
	return (_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << BLUE << "Cette fonction fait le bruit d'un wrong animal\n" << RESET;
}

void	WrongCat::makeSound() const
{
	std::cout << GREEN << "wrong meow.\n" << RESET;
}