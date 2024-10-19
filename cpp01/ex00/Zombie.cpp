/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:18:09 by lboudjel          #+#    #+#             */
/*   Updated: 2024/10/17 20:06:43 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string zombie_name) : name(zombie_name) {}

Zombie::~Zombie(){
	std::cout << GetName() << " has been destroyed." << std::endl;
}

void	Zombie::SetName(std::string name){
	this->name = name;
}

std::string	Zombie::GetName(){
	return (this->name);
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

//malloc = heap
//stack c a la mano

// newZOmbie sur la heap donc avec new 
// randomChump sur la stack a la main