/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:39:42 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/26 22:28:46 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _name) : _name(_name), _HitPoints(100), _EnergyPoints(50), _AttackDamage(20) {
	std::cout << "ClapTrap " << _name << " has been created.\n";
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructor has been called.\n";
}

void		ClapTrap::setName(std::string name){
	this->_name = name;
}

std::string	ClapTrap::getName(){
	return (_name);
}

void		ClapTrap::setEnergyPoints(int cost){
	_EnergyPoints = cost;
}

int		ClapTrap::getEnergyPoints(void) {
	return (_EnergyPoints);
}

void		ClapTrap::setAttackDamage(int amount){
	_AttackDamage = amount;
}

int			ClapTrap::getAttackDamage(void) {
		return (_AttackDamage);
}

void		ClapTrap::setHitPoints(int amount){
	_HitPoints = amount;
}

int			ClapTrap::getHitPoints(void) {
		return (_HitPoints);
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << BLUE << "ClapTrap " << this->_name << " attacks " << target << " causing " << _AttackDamage << " points of damage!" << RESET << std::endl;
	
	this->_EnergyPoints--;
	if (this->_EnergyPoints == 0)
	{
		std::cout << RED << "ClapTrap " << this->_name << " does not have energy anymore !\n" << RESET << std::endl;
		return ;
	}	
	std::cout << this->_name << " has " << this->_EnergyPoints << " energy points left\n" << std::endl; 
}

void 	ClapTrap::takeDamage(unsigned int amount)
{
	this->_HitPoints -= amount;
	if (this->_HitPoints < 0)
		this->_HitPoints = 0;
	std::cout << YELLOW << "ClapTrap " << this->_name << " took " << amount << " damage and has " << this->_HitPoints << " hit points left !" << RESET << std::endl << std::endl;
	if (this->_HitPoints <= 0)
		std::cout << RED << this->_name << " has died :( RIP\n" << RESET << std::endl; 
}


void 	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_EnergyPoints == 0)
	{
		std::cout << RED << "ClapTrap " << this->_name << " does not have enough energy to heal !\n" << RESET << std::endl;
		return ;
	}
	if (this->_HitPoints > 0)
	{
		this->_HitPoints += amount;
		if (this->_HitPoints > 100)
			this->_HitPoints = 100;
		std::cout << GREEN << "ClapTrap " << this->_name << " healed " << amount << " hit point(s) and has now " << this->_HitPoints << " hit points total !" << RESET << std::endl;
	}
	this->_EnergyPoints--;
	if (this->_EnergyPoints >= 0)
		std::cout << this->_name << " has " << this->_EnergyPoints << " energy points left\n" << std::endl;
}
