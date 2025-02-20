/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:07:43 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/19 18:55:48 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include <algorithm>
#include <stack>
#include <string.h>
#include <iostream>
#include <string>
#include <cstdio>

class Errorr : public std::exception {
    public:
        virtual const char* what() const throw();
    };

const char *Errorr::what() const throw() 
{
	return ("Bureaucrat : Grade too low\n");
}

class ErrorOperator : public std::exception {
    public:
        virtual const char* what() const throw();
    };

const char *ErrorOperator::what() const throw() 
{
	return ("operator not used correctly\n");
}

class CharIncorrect : public std::exception {
    public:
        virtual const char* what() const throw();
    };

const char *CharIncorrect::what() const throw() 
{
	return ("not a digit or an operator\n");
}

std::stack<char> mystack;

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

int calc(int v1, int v2, char c)
{
	std::cout << IYELLOW << "v1 : " << v1 << " v2 : " << v2 << RESET <<  std::endl;

	if (c == '*')
		return (v1 * v2);
	if (c == '+')
		return (v1 + v2);
	if (c == '-')
		return (v1 - v2);
	if (c == '/' && v2 != 0)
		return (v1 / v2);
	std::cout << "testtt" << std::endl;
	throw Errorr();
}

int function()
{
	int v1, v2, total;
	char op;
	total = 0;
	int size = mystack.size();
	v1 = mystack.top();
	mystack.pop();

	if (mystack.empty())
		return (total);
	for (int i = 0; mystack.size() > 0; i++)
	{
		if (size - 1 != mystack.size())
			v1 = total;
		if (strchr("+-/*", mystack.top()))
		{
			op = mystack.top();
			mystack.pop();
			v2 = mystack.top();
		}
		else
		{
			v2 = mystack.top();
			mystack.pop();
			op = mystack.top();
		}
		mystack.pop();
		total = calc(v1, v2 , op);
		std::cout << "test" << std::endl;
		std::cout << "v1 -> " << v1 << std::endl;
		std::cout << "v2 -> " << v2 << std::endl;
		std::cout << "op -> " << op << std::endl;
	}
	std::cout << "total -> " << total << std::endl;
	return (total);
}

int main(int argc, char **argv)
{
	try {
		if (argc < 2 || !strchr("+-/*", argv[argc - 1][0]) || (strchr("+-/*", argv[argc - 1][0]) && strchr("+-/*", argv[argc - 2][0])) || strchr("+-/*", argv[1][0]))
			throw ErrorOperator();
		for (int i = argc - 1; i > 0; i--)
		{
			if (argv[i][1])
				return (1);
			if (argv[i][0] >= '0' && argv[i][0] <= '9') {
				argv[i][0] = argv[i][0] - '0';
				mystack.push((argv[i][0]));
			}
			else if (strchr("+-/*", argv[i][0]))
				mystack.push((argv[i][0]));
			else
				throw CharIncorrect();
		}
		try {
			std::cout << function() << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << "ca a foire: " << e.what() << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << "ca a totalement foire: " << e.what() << std::endl;
	}

	return (0);
}
