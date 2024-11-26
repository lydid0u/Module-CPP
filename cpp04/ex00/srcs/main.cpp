/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:50:22 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/26 23:53:34 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

int main()
{
	
	const Animal *meta = new Animal();
	delete(meta);
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	
	// i->makeSound(); //will output the cat sound!
	// j->makeSound();
	
	// meta->makeSound();
	
	// return 0;
}