#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Frag") {
	std::cout << "FragTrap " << _name << " has been created." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destructor has been called.\n";
}

void		FragTrap::setEnergyPoints(int amount){
	_EnergyPoints = amount;
}

void		FragTrap::setAttackDamage(int amount){
	_AttackDamage = amount;
}

void		FragTrap::setHitPoints(int amount){
	_HitPoints = amount;
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