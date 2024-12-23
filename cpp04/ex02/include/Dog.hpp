/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:03:00 by lboudjel          #+#    #+#             */
/*   Updated: 2024/12/23 18:32:29 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : virtual public Animal 
{
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();
        
        virtual std::string getType() const;
        virtual void makeSound() const;
        void setBrainIdea(int n, std::string idea);
        std::string getBrainIdea(int n) const; 
    
    private:
        Brain *cerveau;
        std::string _type;
};

#endif
