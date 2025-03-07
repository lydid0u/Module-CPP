/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:36:10 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/26 21:50:10 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main()
{
	ClapTrap Moha("MOHA");
	ClapTrap Lydia("LYDIA");
	
	std::cout << std::endl;
	
	Moha.attack("LYDIA");
	Lydia.takeDamage(Moha.getAttackDamage());
	Moha.setAttackDamage(2);
	Moha.attack("LYDIA");
	Lydia.takeDamage(Moha.getAttackDamage());
	Lydia.beRepaired(1);
	
	Moha.setAttackDamage(4);
	while (Moha.getEnergyPoints() != 0 && Lydia.getHitPoints() > 0)
	{
		Moha.attack("LYDIA");
		Lydia.takeDamage(Moha.getAttackDamage());
		Lydia.beRepaired(1);
	}
	
	// Moha.setAttackDamage(1);
	// while (Moha.getEnergyPoints() != 0 && Lydia.getHitPoints() > 0)
	// {
	// 	Moha.attack("LYDIA");
	// 	Lydia.takeDamage(Moha.getAttackDamage());
	// 	Lydia.beRepaired(2);
	// }
}