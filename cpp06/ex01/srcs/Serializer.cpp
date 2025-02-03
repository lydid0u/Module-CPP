/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:33:55 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/03 19:25:06 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) {
    *this = other;
}

Serializer &Serializer::operator=(const Serializer &other) {
	if (this != &other)
		*this = other;
    return (*this);
}

Serializer::~Serializer() {}

//adresse -> int
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

// int -> adresse
Data* Serializer::deserialize(std::size_t raw)
{
    return reinterpret_cast<Data*>(raw);
}