/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:55:12 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/26 22:21:05 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
// ClapTrap(), ScavTrap(), FragTrap()

DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name), ScavTrap(), FragTrap() 
{
	ClapTrap::_name = _name + "_clap_name";
	this->_name = _name;
	FragTrap::setHitPoints(90);
	ScavTrap::setEnergyPoints(35);
	// FragTrap::setEnergyPoints(2);
	FragTrap::setAttackDamage(15);
	std::cout << "DiamondTrap " << _name << " has been created." << RESET << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destructor has been called.\n";
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << YELLOW << "Who am i ?\n" << RESET;
	std::cout << "DiamondTrap's name : " << _name << "\nClapTrap's name : " << ClapTrap::_name << std::endl << std::endl;
}