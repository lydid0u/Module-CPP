/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:40:00 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/30 01:39:14 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <ostream>
#include <iostream>
#include <string>

#include "Brain.hpp"


#define RESET   "\033[0m"

#define BOLD        "\033[1m"
#define UNDERLINE   "\033[4m"

#define RED	 	"\033[31m"
#define BLUE	"\033[34m" 
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"


class Animal 
{
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
		virtual std::string getType() const;
		virtual void makeSound() const;
	
	protected:
		std::string _type;
};

// class Dog : virtual public Animal {
// 	protected :
// 		std::string _type;
// 	public :
// 		Dog();
// 		~Dog();
// 		virtual std::string getType() const;
// 		virtual void makeSound() const;
// 		Brain *cerveau;
// };

// class Cat : virtual public Animal {
// 	protected :
// 		std::string _type;
// 	public :
// 		Cat();
// 		~Cat();
// 		virtual std::string getType() const;
// 		virtual void makeSound() const;
// 		Brain *cerveau;
// };

#endif