/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:36:53 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/08 21:19:43 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <ostream>
#include <iostream>
#include <string>

class ClapTrap
{
	private:
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
		void		setName(std::string);
		std::string	getName(void);
		
};

#endif