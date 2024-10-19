/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:16:46 by lboudjel          #+#    #+#             */
/*   Updated: 2024/10/17 20:04:41 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	randomChump("RandomZombie");
	
	Zombie Zombie1("Lydia");
	Zombie1.announce();

	Zombie *Zombie2 = newZombie("NewZombie");
	Zombie2->announce();
	
	delete(Zombie2);
}

//malloc = heap
//stack c a la mano

// newZOmbie sur la heap donc avec new 
// randomChump sur la stack a la main