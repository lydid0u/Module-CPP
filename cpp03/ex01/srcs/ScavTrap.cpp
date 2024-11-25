#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap " << name << " has been created.\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor has been called.\n";
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