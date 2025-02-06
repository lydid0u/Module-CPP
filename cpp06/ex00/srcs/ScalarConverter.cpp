/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:33:55 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/04 15:56:46 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	if (this != &other)
		*this = other;
    return *this;    
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isValidInteger(std::string input) {
    for (size_t i = 0; i < input.length(); i++) {
        if (i == 0 && (input[i] == '+' || input[i] == '-'))
            continue;
        if (input[i] == '.' || input[i] == 'f')
            continue;
        if (!isdigit(input[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::handleSpecialCases(std::string input) {
    std::string specialCases[] = {"nan", "nanf", "inf", "+inf", "-inf", "+inff", "-inff"};
    bool isSpecial = false;

    for (int i = 0; i < 7; ++i) {
        if (input == specialCases[i]) {
            isSpecial = true;
            if (input[input.length() - 1] == 'f') {
                input = input.substr(0, input.length() - 1);
            }
            break;
        }
    }

    if (isSpecial) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << "f" << std::endl;
        std::cout << "double: " << input << std::endl;
        return true;
    }

    return false;
}

// str to long -> puis checker si cest pas une string genre "hello" / que la valeur est bien celle d'un char / que c'est ni imprimable, ni une lettre 
void ScalarConverter::convertToChar(std::string input) {
    std::cout << "char: ";

    long value = std::strtol(input.c_str(), NULL, 10);

    if ((input.length() != 1 && !isValidInteger(input)) || value < std::numeric_limits<char>::min() || 
            value > std::numeric_limits<char>::max() || (!isprint(value) && !std::isalpha(input[0]))) 
    {
        std::cout << RED << "Non displayable" << RESET << std::endl;
        return;
    }

    //soit on converti le long en char, soit cest deja le char et on l'ecrit juste
    if (isValidInteger(input))
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "'" << input[0] << "'" << std::endl;
}

void ScalarConverter::convertToInt(std::string input) {
    std::cout << "int: ";

    long value = std::strtol(input.c_str(), NULL, 10);

    if (value <= LONG_MIN || value >= LONG_MAX) {
        std::cout << RED << "Non displayable" << RESET << std::endl;
        return;
    }

    //si cest un char tout seul on affiche son code en ASCII
    if (std::isalpha(input[0]) && input.length() == 1) {
        std::cout << static_cast<int>(input[0]) << std::endl;
        return;
    }

    if (!isValidInteger(input)) {
        std::cout << RED << "Non displayable" << RESET << std::endl;
        return;
    }

    std::cout << static_cast<int>(value) << std::endl;
}

//string to float
void ScalarConverter::convertToFloat(std::string input) {
    std::cout << "float: " << std::strtof(input.c_str(), NULL) << ".0f" << std::endl;
}

//string to double + fixed et setprecision pour garder 1 chiffre apres la virgule
void ScalarConverter::convertToDouble(std::string input) {
    std::cout << "double: " << std::fixed << std::setprecision(1) << std::strtod(input.c_str(), NULL) << std::endl;
}

void ScalarConverter::convert(std::string input) {
    if (handleSpecialCases(input))
        return;

    convertToChar(input);
    convertToInt(input);
    convertToFloat(input);
    convertToDouble(input);
}