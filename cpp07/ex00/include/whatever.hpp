/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:11:58 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/05 16:12:01 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

#define RESET   "\033[0m"
#define RED	 "\033[31m"
#define BLUE	"\033[34m" 
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"

template <typename S>
void swap(S& a, S& b) {
    S c = a;
	a = b;
	b = c;
}

template <typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

#endif 