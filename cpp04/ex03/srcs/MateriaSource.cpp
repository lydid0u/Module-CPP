/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:46:32 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/18 16:46:32 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        this->templates[i] = NULL;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        if (this->templates[i])
            delete this->templates[i];
}

MateriaSource::MateriaSource(MateriaSource const & src) {
    for (int i = 0; i < 4; i++)
        this->templates[i] = src.templates[i] ? src.templates[i]->clone() : NULL;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 4; i++) {
            if (this->templates[i])
                delete this->templates[i];
            this->templates[i] = rhs.templates[i] ? rhs.templates[i]->clone() : NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < 4; i++) {
        if (!this->templates[i]) {
            this->templates[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++)
        if (this->templates[i] && this->templates[i]->getType() == type)
            return this->templates[i]->clone();
    return NULL;
}
