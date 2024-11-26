#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Scav") {
	std::cout << "ScavTrap " << _name << " has been created." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destructor has been called.\n";
}

void	ScavTrap::setHitPoints(int amount)
{
	_HitPoints = amount;
}

void	ScavTrap::setEnergyPoints(int amount)
{
	_EnergyPoints = amount;
}

void	ScavTrap::setAttackDamage(int amount)
{
	_AttackDamage = amount;
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << BLUE << "ScavTrap " << this->_name << " attacks " << target << " causing " << _AttackDamage << " points of damage!" << RESET << std::endl;
	
	this->_EnergyPoints--;
	if (this->_EnergyPoints == 0)
	{
		std::cout << RED << "ScavTrap " << this->_name << " does not have energy anymore !\n" << RESET << std::endl;
		return ;
	}	
	std::cout << this->_name << " has " << this->_EnergyPoints << " energy points left\n" << std::endl; 
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode.\n" << std::endl;
}