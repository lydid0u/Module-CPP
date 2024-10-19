/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:37:29 by lboudjel          #+#    #+#             */
/*   Updated: 2024/10/19 18:04:51 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon(){}

const std::string&	Weapon::getType() const {
	return(type);
}

void	Weapon::setType(std::string type){
	this->type = type;
}