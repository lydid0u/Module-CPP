/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:22:18 by lboudjel          #+#    #+#             */
/*   Updated: 2024/12/23 20:21:51 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

void Character::clearInventory() {
    for (int i = 0; i < 4; i++) {
        delete _inventory[i];
        _inventory[i] = nullptr;
    }
}

Character::Character(std::string name) : _name(name) {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = nullptr;
    }
}

Character::Character(const Character& other) : _name(other._name) {
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i]) {
            _inventory[i] = other._inventory[i]->clone();
        }
        else {
            _inventory[i] = nullptr;
        }
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        _name = other._name;
        clearInventory();
        for (int i = 0; i < 4; i++) {
            if (other._inventory[i]) {
                _inventory[i] = other._inventory[i]->clone();
            }
            else {
                _inventory[i] = nullptr;
            }
        }
    }
    return *this;
}

Character::~Character() {
    clearInventory();
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m) {
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] == nullptr) {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        _inventory[idx] = nullptr;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4) {
        if (_inventory[idx]) {
            _inventory[idx]->use(target);
        }
    }
}
