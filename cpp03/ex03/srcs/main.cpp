/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:36:10 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/26 22:24:54 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"


int main()
{
	std::cout << BG_CYAN;
	ClapTrap 	Lydia("Lydia");
	std::cout << BG_MAGENTA;
	FragTrap	Frag;
	std::cout << BG_BLUE;
	ScavTrap	Scav;
	std::cout << BG_GREEN;
	DiamondTrap	Diamond("SIRINE_DIAMOND");

	
	std::cout << std::endl;
	Diamond.whoAmI();
	std::cout << GREEN << "HitPoints : " << Diamond.getHitPoints() << RESET << std::endl;
	std::cout << BLUE << "EnergyPoints : " << Diamond.getEnergyPoints() << RESET << std::endl;
	std::cout << RED << "AttackDamage : " << Diamond.getAttackDamage() << RESET << std::endl;
	std::cout << std::endl;
	
	std::cout << "-----------------------------------------------\n";
	
	Lydia.attack("SIRINE_DIAMOND");
	Diamond.takeDamage(Lydia.getAttackDamage());
	Diamond.beRepaired(15);
	Diamond.attack("MOHAFrag");
	
	// Frag.highFivesGuys();
}
