/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:18:09 by lboudjel          #+#    #+#             */
/*   Updated: 2024/10/18 19:13:48 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie(){
	std::cout << name << " has been destroyed." << std::endl;
}

void	Zombie::setName(std::string name){
	this->name = name;
}

void	Zombie::announce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

//malloc = heap
//stack c a la mano

// newZOmbie sur la heap donc avec new 
// randomChump sur la stack a la main