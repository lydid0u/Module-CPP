/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:36:53 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/15 18:14:15 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <ostream>
#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED	 	"\033[31m"
#define BLUE	"\033[34m" 
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m" 

class ClapTrap
{
	protected:
		std::string _name;
		int _HitPoints;
		int _EnergyPoints;
		int _AttackDamage;
		
	public:
		ClapTrap(std::string name);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		//setters & getters
		std::string	getName(void);
		void		setName(std::string);
		void		setEnergyPoints(int cost);
		int 		getEnergyPoints();
		void		setAttackDamage(int amount);
		int 		getAttackDamage();
		void		setHitPoints(int amount);
		int 		getHitPoints();
};

#endif