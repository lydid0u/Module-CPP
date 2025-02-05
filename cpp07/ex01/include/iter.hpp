/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:12:26 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/05 16:12:35 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
#include <ctype.h> 

#define RESET   "\033[0m"
#define RED	 "\033[31m"
#define BLUE	"\033[34m" 
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"

template <typename I, typename F>
void iter(I& adress, int length, F function) {
    for (int i = 0; i < length; i++)
    {
        function(adress[i]);
    }
}

#endif 