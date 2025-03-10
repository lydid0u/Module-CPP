/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:00:39 by lboudjel          #+#    #+#             */
/*   Updated: 2025/03/10 23:26:54 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include "colors.hpp"
#include <algorithm>
#include <stack>
#include <string.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <sstream>

class notEnoughNumberStack : public std::exception {
    public:
        virtual const char* what() const throw();
};

class ErrorOperator : public std::exception {
    public:
        virtual const char* what() const throw();
};

class CharIncorrect : public std::exception {
    public:
        virtual const char* what() const throw();
};

class isANumber : public std::exception {
    public:
        virtual const char* what() const throw();
};

class numberLeftStack : public std::exception {
    public:
        virtual const char* what() const throw();
};

class notEnoughArgument : public std::exception {
    public:
        virtual const char* what() const throw();
};

#endif