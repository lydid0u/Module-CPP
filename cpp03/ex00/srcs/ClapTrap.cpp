/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:39:42 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/08 21:20:45 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {
	std::cout << "ClapTrap " << name << " has been created.\n";
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor has been called.\n";
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _AttackDamage << " points of damage!" << std::endl;
}

// void takeDamage(unsigned int amount);
