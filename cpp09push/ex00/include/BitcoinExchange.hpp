/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:26:20 by lboudjel          #+#    #+#             */
/*   Updated: 2025/03/10 23:39:25 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>
#include "colors.hpp"

class BitcoinExchange {
    private:
        std::map<std::string, double> btc;
        
        bool isValidDate(int year, int month, int day);
        void parseDate(const std::string& date);
        void parseRate(const std::string& valueInput);
        double getExchangeRate(const std::string& date);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void checkDataBase(std::string filename);
        void checkInputFile(std::string filename);
};

#endif 