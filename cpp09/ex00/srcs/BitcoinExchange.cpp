/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:15:27 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/18 19:23:34 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// BitcoinExchange.cpp
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : btc(other.btc) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        btc = other.btc;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(int year, int month, int day) {
    if ((year < 2009 || year > 2024) || (month < 1 || month > 12) || (day < 1 || day > 31))
        return false;

    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (month == 2) {
        if (isLeapYear)
            return day <= 29;
        return day <= 28;
    }

    return day <= daysInMonth[month];
}

void BitcoinExchange::parseDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw std::runtime_error("Error: invalid date format => " + date);

    std::string year_str = date.substr(0, 4);
    std::string month_str = date.substr(5, 2);
    std::string day_str = date.substr(8, 2);
	
    int year = std::atoi(year_str.c_str());
    int month = std::atoi(month_str.c_str());
    int day = std::atoi(day_str.c_str());

    if (!isValidDate(year, month, day))
        throw std::runtime_error("Error: bad input => " + date);
}

void BitcoinExchange::parseRate(const std::string& valueInput) {
    char *end;
    double value = std::strtod(valueInput.c_str(), &end);
    
    if (*end != '\0')
        throw std::runtime_error("Error: invalid value format => " + valueInput);
    if (value < 0)
        throw std::runtime_error("Error: not a positive number => " + valueInput);
    if (value > 1000)
        throw std::runtime_error("Error: number too large (bigger than 1000) => " + valueInput);
}

double BitcoinExchange::getExchangeRate(const std::string& date) {
    std::map<std::string, double>::iterator it = btc.lower_bound(date);
    
    if (it == btc.begin() && it->first != date)
        throw std::runtime_error("Error: bitcoin was created january 3rd 2009, so there is no data available before this date !");

    if (it == btc.end() || it->first != date)
        --it;
    
    return it->second;
}

void BitcoinExchange::checkDataBase(std::string filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open data.csv file");

    std::string line;
    std::getline(file, line);
    
    while(std::getline(file, line)) {
        try {
            size_t pos = line.find(',');
            if (pos == std::string::npos) {
                throw std::runtime_error("Error: invalid format =>" + line);
            }
            
            std::string date = line.substr(0, pos);
            std::string rate = line.substr(pos + 1);
            
            parseDate(date);
            double value = std::strtod(rate.c_str(), NULL);
            if (value < 0) {
                throw std::runtime_error("Error: negative value in database");
            }
            
            btc[date] = value;
        }
        catch(const std::exception& e) {
            std::cerr << IRED << e.what() << RESET << std::endl;
        }
    }
}

void BitcoinExchange::checkInputFile(std::string filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open input file.");

    std::string line;
    std::getline(file, line);
    
    while(std::getline(file, line)) {
        try {
            size_t pos = line.find(" | ");
            if (pos == std::string::npos)
                throw std::runtime_error("Error: bad input => " + line);
            
            std::string date = line.substr(0, pos);
            std::string valueInput = line.substr(pos + 3);
            
			
            parseDate(date);
            parseRate(valueInput);
            
            double value = std::strtod(valueInput.c_str(), NULL);
            double rate = getExchangeRate(date);
            
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
        }
        catch(const std::exception& e) {
            std::cerr << IRED << e.what() << RESET << std::endl;
        }
    }
}