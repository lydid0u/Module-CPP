/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:57:42 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/14 19:17:38 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//traite str comme une entree (comme cin) et on en extrait un int
int stringToInt(const std::string& str) {
	std::istringstream string_date(str);
	int int_date;
	
	string_date >> int_date;
	
	return int_date;
}

void	BitcoinExchange::parseDate(std::string date) {
	// if (date.length() < 10 || date[4] != '-' || date[7] != '-') {
    // 	std::cerr << "Error: Invalid date format => " << date << std::endl;
   	//  	return;
	// }

	std::string year_str = date.substr(0, 4); 
	std::string month_str = date.substr(5, 2);
	std::string day_str = date.substr(8, 2);  

	int year = stringToInt(year_str);
	int month = stringToInt(month_str);
	int day = stringToInt(day_str);

	if ((year < 1980 || year > 2025) || (month < 1 || month > 12) || (day < 1 || day > 31))
		std::cerr << "Error : bad input => " << date << std::endl;
	std::cout << "Année  : " << year << std::endl;
	std::cout << "Mois   : " << month << std::endl;
	std::cout << "Jour   : " << day << std::endl;
	
}

int	BitcoinExchange::openingFile(std::ifstream &file) {
	std::string		line;
	char delimiteur = ',';
	while(getline(file, line)) 
	{
		if (line.empty()) {
    	std::cerr << "Error: Empty line encountered." << std::endl;
    	continue;
		}
		size_t position = line.find(delimiteur);
	
		if (position != std::string::npos) {
			std::string date = line.substr(0, position);
			parseDate(date);
			std::string rate = line.substr(position + 1);
		} 
		else {
			std::cerr << "An error occured with the line : " << line << std::endl;
			return (1);
		}
	}
	return (0);
}