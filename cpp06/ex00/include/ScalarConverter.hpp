/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:09:08 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/03 15:55:52 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <limits>
#include <limits.h>
#include <exception>
#include <iomanip> 

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m" 
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m" 

class ScalarConverter {
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &copy);
        ~ScalarConverter(void);
        
        ScalarConverter &operator=(const ScalarConverter &copy);

        static bool isValidInteger(std::string input);
        static bool handleSpecialCases(std::string input);
        static void convertToChar(std::string input);
        static void convertToInt(std::string input);
        static void convertToFloat(std::string input);
        static void convertToDouble(std::string input);

    public:
        static void convert(std::string input);
};

#endif 