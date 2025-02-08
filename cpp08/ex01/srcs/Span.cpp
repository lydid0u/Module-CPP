/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:28:39 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/08 19:11:28 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _N(N) {
	_vector.resize(_N);
}

Span::Span(const Span& other) {
	*this = other;	
}

Span& Span::operator=(const Span& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) 
		_N = other._N;
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int number) {
	// try {
	// 	if (_N == )
		_vector.push_back(number);
		std::cout << _vector[5] << std::endl;
	// }
}
