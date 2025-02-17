/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:29:19 by lboudjel          #+#    #+#             */
/*   Updated: 2024/12/23 16:00:59 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : virtual public Animal 
{
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();
		
		virtual std::string getType() const;
		virtual void makeSound() const;
		void setBrainIdea(int n, std::string idea); // Nouvelle méthode
		std::string getBrainIdea(int n) const; 
	private:
		Brain *cerveau;
		std::string _type;
};

#endif