/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:49:22 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/26 21:36:06 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    public :
        ScavTrap();
        ~ScavTrap();
        void setEnergyPoints(int amount);
		void setAttackDamage(int amount);
		void setHitPoints(int amount);
        void attack(const std::string& target);
        void guardGate();
};

#endif               