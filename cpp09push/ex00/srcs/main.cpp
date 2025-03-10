/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:07:43 by lboudjel          #+#    #+#             */
/*   Updated: 2025/03/10 23:38:32 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc == 2) {
    	try {
    	    BitcoinExchange btc;
    	    
			btc.checkDataBase("data.csv");
    	   	btc.checkInputFile(argv[1]);
    	}
    	catch(const std::exception& e) {
    	    std::cerr << IRED << e.what() << RESET << std::endl;
    	    return 1;
    	}
	} else {
		std::cerr << RED << "Error: could not open file => " << BLUE << "<./btc + \"input.txt\">" << RESET << std::endl;
		return (1);
	}
    return (0);
}