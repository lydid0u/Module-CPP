/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:02:52 by lboudjel          #+#    #+#             */
/*   Updated: 2024/12/23 18:32:29 by lboudjel         ###   ########.fr       */
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
        void setBrainIdea(int n, std::string idea);
        std::string getBrainIdea(int n) const; 
    
    private:
        Brain *cerveau;
        std::string _type;
};

#endif
