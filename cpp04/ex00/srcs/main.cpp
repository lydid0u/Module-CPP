/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:50:22 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/29 19:29:56 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"


int main()
{
	
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	
	std::cout << std::endl;
	
	std::cout << RED << "Type : " << j->getType() << " " << RESET << std::endl;
	std::cout << GREEN << "Type : " << i->getType() << " " << RESET << std::endl;
	
	std::cout << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	std::cout << std::endl;
	
	std::cout << BLUE << meta->getType() << " \n" << RESET << std::endl;
	
	delete(meta);
	delete(i);
	delete(j);
	
	return 0;
}