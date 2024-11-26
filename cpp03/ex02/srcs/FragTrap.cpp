#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap " << name << " has been created.\n";
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destructor has been called.\n";
}

void	FragTrap::attack(const std::string& target)
{
	std::cout << BLUE << "FragTrap " << this->_name << " attacks " << target << " causing " << _AttackDamage << " points of damage!" << RESET << std::endl;
	
	this->_EnergyPoints--;
	if (this->_EnergyPoints == 0)
	{
		std::cout << RED << "FragTrap " << this->_name << " does not have energy anymore !\n" << RESET << std::endl;
		return ;
	}	
	std::cout << this->_name << " has " << this->_EnergyPoints << " energy points left\n" << std::endl; 
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " request a positive high five !\n" << std::endl;
}