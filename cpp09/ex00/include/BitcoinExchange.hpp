/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:26:20 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/14 18:52:57 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include "colors.hpp"
#include <fstream>
#include <map>
#include <algorithm>

enum Type {
    INT, 
    FLOAT
};

struct Valeur {
    Type type;
    union {
        int i;
        float f;
    };

    Valeur(int val) : type(INT), i(val) {}
    Valeur(float val) : type(FLOAT), f(val) {}
};

class BitcoinExchange {
	public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	static int	openingFile(std::ifstream &file);
	static void	parseDate(std::string date);
	
	private:
	std::map<std::string, Valeur> btc;
};

#endif 