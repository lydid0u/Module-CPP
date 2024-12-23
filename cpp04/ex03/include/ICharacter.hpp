/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:43:17 by lboudjel          #+#    #+#             */
/*   Updated: 2024/12/23 19:28:19 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ICharacter.hpp
#pragma once
#ifndef ICharacter_HPP
#define ICharacter_HPP

#include <iostream>
#include "AMateria.hpp"

class ICharacter {
public:
	// ICharacter();
	// ICharacter(const ICharacter& other);
	// ICharacter& operator=(const ICharacter& other);
	// ~ICharacter();
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;

private:
	// Add member variables here
};

#endif // ICharacter_HPP