/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:40:00 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/27 00:01:57 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <ostream>
#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED	 	"\033[31m"
#define BLUE	"\033[34m" 
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

class	Animal {
	protected :
		std::string _type;
	public :
		Animal();
		~Animal();
};

class Dog : virtual public Animal {
	protected :
		std::string _type;
	public :
		Dog();
		~Dog();
		void makesound();
};

class Cat : virtual public Animal {
	protected :
		std::string _type;
	public :
		Cat();
		~Cat();
		void makesound();
};
// class Cat : public Animal {
// 	public :
// 		void makesound();
// };

// class animal {
// public:
// 	animal();

// 	animal(const animal& other);

// 	animal& operator=(const animal& other);

// 	~animal();

// private:
// 	// Add member variables here
// };

#endif