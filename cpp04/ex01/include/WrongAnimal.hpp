/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnima.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:17:40 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/29 18:17:41 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

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

// ClassName.hpp
#ifndef ClassName_HPP
#define ClassName_HPP

#include <iostream>

class ClassName {
public:
	ClassName();
	ClassName(const ClassName& other);
	ClassName& operator=(const ClassName& other);
	~ClassName();

private:
	// Add member variables here
};

#endif // ClassName_HPP
class	WrongAnimal {
	protected :
		std::string _type;
	public :
		WrongAnimal();
		virtual ~WrongAnimal();
		std::string getType() const;
		void makeSound() const;
};

class WrongCat : public WrongAnimal {
	protected :
		std::string _type;
	public :
		WrongCat();
		~WrongCat();
		std::string getType() const;
		void makeSound() const;
};

// class Cat : public WrongAnimal {
// 	public :
// 		void makesound();
// };

// class Wronganimal {
// public:
// 	Wronganimal();

// 	Wronganimal(const Wronganimal& other);

// 	Wronganimal& operator=(const Wronganimal& other);

// 	~Wronganimal();

// private:
// 	// Add member variables here
// };

#endif