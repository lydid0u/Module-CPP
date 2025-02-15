/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:07:43 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/12 17:40:04 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Format dans fichier csv -> YYYY-MM-DD,Value = 2021-09-21,42901.56
// Format dans infile date | value = 2011-01-03 | 3
// Ouvrir le fichier, check les droits, lire tout le fichier et check les dates + valeurs
// Parsing -> Format Date = 0YYYY4-MM-DD YYYY = 0-2025, 0-12, 0-31
// Valeur entre 0 - 1000 : Flotant ou int
// Trouver dans fichier infile le nombre de btc et trouver la valeur avec la date la plus proche
// Afficher Date => Nbr de btc = Valeur a la date

int main(int argc, char **argv) 
{
	if (argc == 2) {
		std::ifstream file(argv[1]);
		if (file.is_open())
			::BitcoinExchange::openingFile(file);
		else
			std::cerr << "An error occured while opening the file : " << argv[1] << std::endl;
	}
	else
	{
		std::cout << "Error you need one argument : " << BLUE << "<./btc + \"file.txt\">" << std::endl;
		return (1);
	}
	return (0);
}