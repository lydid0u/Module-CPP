/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:28:39 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/10 19:05:51 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _N(N) {}

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

const char *Span::vectorFull::what() const throw() 
{
    return ("Vector is already full, can't add the value");
}

const char *Span::vectorNull::what() const throw() 
{
    return ("Vector is empty or contain only one value ");
}

void	Span::addNumber(int number) {
	try {
		if (_N <= _vector.size())
			throw vectorFull(); 
		_vector.push_back(number);
	}
	catch (const vectorFull &e) {
		std::cerr << CRED << "Error : " << BRED << e.what() << " : can't search for the span" << RESET << std::endl; 
	}
}

int		Span::shortestSpan() {
	try {
		if (_N <= 1)
			throw vectorNull();
			
    	std::sort(_vector.begin(), _vector.end()); 
	
    	int minSpan = std::numeric_limits<int>::max();
    	
		for (size_t i = 1; i < _vector.size(); ++i)
    	    minSpan = std::min(minSpan, _vector[i] - _vector[i - 1]);
		return minSpan;
	}
	catch (const vectorNull &e) {
		std::cerr << CRED << "Error : " << BRED << e.what() << RESET << std::endl; 
		return 0;
	}
}

int		Span::longestSpan() {
	try {
		if (_N <= 1)
			throw vectorNull();
    	std::sort(_vector.begin(), _vector.end()); 
	
    	int maxSpan = _vector.back() - _vector[0];

		return (maxSpan);
	}
	catch (const vectorNull &e) {
		std::cerr << CRED << "Error : " << BRED << e.what() << RESET << std::endl; 
		return (0);
	}
}

void	Span::fillingWithRandomNumber() {
	try {
		if (_N == 0)
			throw vectorNull();
		std::srand(std::time(NULL));
		for (unsigned int i = 0; i < _N; i++)
			_vector.push_back(rand());
	}
	catch (const vectorFull &e) {
		std::cerr << CRED << "Error : " << BRED << e.what() << " : can't fill the vector" << RESET << std::endl; 
	}
}