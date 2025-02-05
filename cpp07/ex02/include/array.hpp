/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:47:24 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/05 16:43:53 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

#define RESET   "\033[0m"
#define RED	 "\033[31m"
#define BLUE	"\033[34m" 
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"

template <typename T>
class Array
{
	public:
		//constructor/destructor
		Array() : _array(new T[0]), _len(0) {
			std::cout << YELLOW << "Default Constructor has been called" << RESET << std::endl;
		}
		Array(unsigned int n) : _array(new T[n]), _len(n) {
			std::cout << YELLOW << "Constructor has been called" << RESET << std::endl;
		}
		Array(const Array<T> &other) : _array(new T[other._len]), _len(other._len){
			std::cout << YELLOW << "Copy constructor has been called" << RESET << std::endl;
			for (unsigned int i = 0; i < _len; i++)
			{
				_array[i] = other._array[i];
			}
		}
		Array	&operator=(const Array<T> &other) {
			std::cout << YELLOW << "Copy assignment operator has been called" << RESET << std::endl;
			if (this != &other)
			{
				delete[] _array;
				_array = new T[other._len]();
				_len = other._len;
				
				for (unsigned int i = 0; i < _len; i++)
				{
					_array[i] = other._array[i];
				}
			}
			return (*this);
		}
		~Array() {
			std::cout << YELLOW << "Destructor has been called" << RESET << std::endl;
			delete [] _array;
		}

		//function
		T 				&operator[](unsigned int i) {
			if (i >= _len || i < 0)
				throw std::out_of_range("index is out of bounds !");
			return (_array[i]);
		}
		unsigned int	size() const {
			return _len;
		}

	private:
		T				*_array;
		unsigned int	_len;
};

#endif

