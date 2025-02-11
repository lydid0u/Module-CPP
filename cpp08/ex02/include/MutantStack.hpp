/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:54:00 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/11 15:10:58 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <string>
#include <list>
#include "colors.hpp"

template <typename T>
class MutantStack : public std::stack<T> 
{
    public :
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator=(const MutantStack &other);
        ~MutantStack();
        
        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin();
        iterator end();
};

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &other) {
    this->c = other.c;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return(this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return(this->c.end());
}

#endif