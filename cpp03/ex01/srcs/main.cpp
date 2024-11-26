/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:36:10 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/26 18:13:27 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int main()
{
	ScavTrap	Scav("MOHASCAV");
	ClapTrap Lydia("LYDIA");
	
	std::cout << std::endl;
	
	Scav.attack("LYDIA");
	Lydia.takeDamage(Scav.getAttackDamage());
	Lydia.beRepaired(1);
	Lydia.attack("MOHASCAV");
	
	Scav.guardGate();
}
	
	// Moha.setAttackDamage(1);
	// while (Moha.getEnergyPoints() != 0 && Lydia.getHitPoints() > 0)
	// {
	// 	Moha.attack("LYDIA");
	// 	Lydia.takeDamage(Moha.getAttackDamage());
	// 	Lydia.beRepaired(2);
	// }
