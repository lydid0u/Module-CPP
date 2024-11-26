/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:36:53 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/26 22:15:41 by lboudjel         ###   ########.fr       */
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
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define BG_YELLOW   "\033[43m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_CYAN     "\033[46m"

class ClapTrap
{
	protected:
		std::string _name;
		int _HitPoints;
		int _EnergyPoints;
		int _AttackDamage;
		
	public:
		ClapTrap(std::string _name);
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