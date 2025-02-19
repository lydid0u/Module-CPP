/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:07:43 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/18 20:24:39 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include <algorithm>
#include <stack>
#include <string.h>
#include <iostream>
#include <string>
#include <cstdio>


// Format dans fichier csv -> YYYY-MM-DD,Value = 2021-09-21,42901.56
// Format dans infile date | value = 2011-01-03 | 3
// Ouvrir le fichier, check les droits, lire tout le fichier et check les dates + valeurs
// Parsing -> Format Date = 0YYYY4-MM-DD YYYY = 0-2025, 0-12, 0-31
// Valeur entre 0 - 1000 : Flotant ou int
// Trouver dans fichier infile le nombre de btc et trouver la valeur avec la date la plus proche
// Afficher Date => Nbr de btc = Valeur a la date

// main.cpp
std::stack<char> mystack;

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
	throw "ntm";
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
			if (mystack.empty())
				return (total);
			v2 = mystack.top();
		}
		else
		{
			v2 = mystack.top();
			std::cout << "v2 : " << v2 << std::endl;
			mystack.pop();
			if (mystack.empty())
				return (total);
			op = mystack.top();
			std::cout << "op : " << op << std::endl;
		}
		mystack.pop();
		if (mystack.empty())
			return (total);
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
		if (argc < 2)
			return (1);
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
				throw "not a digit or an operator";
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
