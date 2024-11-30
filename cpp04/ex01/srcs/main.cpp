/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:50:22 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/30 01:55:51 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal *i = new Cat();
	const Animal *j = new Dog();
	
	std::cout << BOLD RED << "\nTableau d'objets Animal : \n" << RESET;
	const Animal *Dog_Cat[6];
	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
		{
			Dog_Cat[i] = new Cat();
			Dog_Cat[i]->makeSound();
		}
		else
		{
			Dog_Cat[i] = new Dog();
			Dog_Cat[i]->makeSound();
		}
	}
	
	std::cout << BOLD RED << "\nDelete le tableau : \n" << RESET;
	for (int i = 0; i < 6; i++)
		delete Dog_Cat[i];

	std::cout << BOLD RED << "\nChecker la deep copy : \n" << RESET;
	Dog chien;
	chien.cerveau->setIdea(3, "Je suis un chien.");
	std::cout << YELLOW << chien.cerveau->getIdea(3) << RESET << std::endl;
	Dog shee_un = chien;
	std::cout << MAGENTA << shee_un.cerveau->getIdea(3) << RESET << std::endl;
	shee_un.cerveau->setIdea(3, "Je suis un shee_un !");
	std::cout << "shee_uns new idea : " << shee_un.cerveau->getIdea(3) << std::endl;
	std::cout << "chien's idea : "<< chien.cerveau->getIdea(3) << std::endl;

	std::cout << std::endl;
	
	delete j;
	delete i;

	return 0;

}