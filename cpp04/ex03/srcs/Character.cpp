/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:06:20 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/18 17:06:20 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
        if (this->inventory[i])
            delete this->inventory[i];
}

Character::Character(Character const & src) : name(src.name) {
    for (int i = 0; i < 4; i++)
        this->inventory[i] = src.inventory[i] ? src.inventory[i]->clone() : NULL;
}

Character & Character::operator=(Character const & rhs) {
    if (this != &rhs) {
        this->name = rhs.name;
        for (int i = 0; i < 4; i++) {
            if (this->inventory[i])
                delete this->inventory[i];
            this->inventory[i] = rhs.inventory[i] ? rhs.inventory[i]->clone() : NULL;
        }
    }
    return *this;
}

std::string const & Character::getName() const {
    return this->name;
}

void Character::equip(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < 4; i++) {
        if (!this->inventory[i]) {
            this->inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4)
        this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && this->inventory[idx])
        this->inventory[idx]->use(target);
}
