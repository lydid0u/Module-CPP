/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:50:22 by lboudjel          #+#    #+#             */
/*   Updated: 2024/12/05 23:40:34 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	
	std::cout << std::endl;
	
	std::cout << RED << "Type : " << j->getType() << " " << RESET << std::endl;
	std::cout << GREEN << "Type : " << i->getType() << " " << RESET << std::endl;
	std::cout << BLUE << "Type : " << meta->getType() << " " << RESET << std::endl;
	
	std::cout << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	std::cout << std::endl;
	
	delete(meta);
	delete(i);
	delete(j);
	
	std::cout << "\n--------------------------------------\n\n";
	
	const WrongAnimal *wrong_i = new WrongAnimal();
	WrongCat Wrong_Cat;
	
	std::cout << BLUE << "\nType : " << wrong_i->getType() << " " << RESET << std::endl;
	std::cout << RED << "\nType : " << Wrong_Cat.getType() << " " << RESET << std::endl;
	
	std::cout << std::endl;

	wrong_i->makeSound(); 
	Wrong_Cat.makeSound();
	
	std::cout << std::endl;
	
	delete(wrong_i);
	
	return 0;
}