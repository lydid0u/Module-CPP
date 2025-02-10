/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:09:08 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/10 19:06:27 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
#include <ctime>
#include "colors.hpp"

class Span {
public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();
	void	addNumber(int number);
	int		shortestSpan();
	int		longestSpan();
	void	fillingWithRandomNumber();

    class vectorFull : public std::exception {
        public:
            virtual const char* what() const throw();
    };
	class vectorNull : public std::exception {
        public:
            virtual const char* what() const throw();
    };
	
private:
	unsigned int _N;
	std::vector<int>	_vector;
};

#endif