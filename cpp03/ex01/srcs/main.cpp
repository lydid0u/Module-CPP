/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:36:10 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/15 18:44:25 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int main()
{
	ScavTrap	scav("MOHASCAV");
	// ClapTrap Moha("MOHA");
	// ClapTrap Lydia("LYDIA");
	
	std::cout << std::endl;
	
	scav.attack("LYDIA");
	// Lydia.beRepaired(1);
}
	
	// Moha.setAttackDamage(1);
	// while (Moha.getEnergyPoints() != 0 && Lydia.getHitPoints() > 0)
	// {
	// 	Moha.attack("LYDIA");
	// 	Lydia.takeDamage(Moha.getAttackDamage());
	// 	Lydia.beRepaired(2);
	// }
