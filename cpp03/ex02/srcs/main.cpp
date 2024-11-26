/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:36:10 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/26 18:28:12 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/FragTrap.hpp"

int main()
{
	FragTrap	Frag("MOHAFRAG");
	ClapTrap Lydia("LYDIA");
	
	std::cout << std::endl;
	
	Frag.attack("LYDIA");
	Lydia.takeDamage(Frag.getAttackDamage());
	Lydia.beRepaired(1);
	Lydia.attack("MOHAFrag");
	
	Frag.highFivesGuys();
}
	
	// Moha.setAttackDamage(1);
	// while (Moha.getEnergyPoints() != 0 && Lydia.getHitPoints() > 0)
	// {
	// 	Moha.attack("LYDIA");
	// 	Lydia.takeDamage(Moha.getAttackDamage());
	// 	Lydia.beRepaired(2);
	// }
