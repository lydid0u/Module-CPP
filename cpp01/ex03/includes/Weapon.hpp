/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:38:19 by lboudjel          #+#    #+#             */
/*   Updated: 2024/10/19 18:07:45 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>


class Weapon
{
private:
	std::string	type;
public:
	Weapon(std::string type);
	~Weapon();
	const std::string&	getType() const;
	void	setType(std::string);
};

#endif