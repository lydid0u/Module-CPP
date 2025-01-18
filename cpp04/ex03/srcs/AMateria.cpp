/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:06:38 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/18 17:06:39 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::~AMateria() {}

AMateria::AMateria(AMateria const & src) : type(src.type) {}

AMateria & AMateria::operator=(AMateria const & rhs) {
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

std::string const & AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
}