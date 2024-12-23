/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:28:47 by lboudjel          #+#    #+#             */
/*   Updated: 2024/12/23 20:28:50 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

void MateriaSource::clearTemplates() {
    for (int i = 0; i < 4; i++) {
        delete _templates[i];
        _templates[i] = nullptr;
    }
}

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        _templates[i] = nullptr;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; i++) {
        if (other._templates[i]) {
            _templates[i] = other._templates[i]->clone();
        }
        else {
            _templates[i] = nullptr;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        clearTemplates();
        for (int i = 0; i < 4; i++) {
            if (other._templates[i]) {
                _templates[i] = other._templates[i]->clone();
            }
            else {
                _templates[i] = nullptr;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    clearTemplates();
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) {
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (_templates[i] == nullptr) {
            _templates[i] = m->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (_templates[i] && _templates[i]->getType() == type) {
            return _templates[i]->clone();
        }
    }
    return nullptr;
}