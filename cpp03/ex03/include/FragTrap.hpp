/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:49:19 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/26 21:37:07 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTRAP_HPP
# define FragTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
    public :
        FragTrap();
        ~FragTrap();
        void attack(const std::string& target);
        void setEnergyPoints(int cost);
		void setAttackDamage(int amount);
		void setHitPoints(int amount);
        void highFivesGuys();
};

#endif               