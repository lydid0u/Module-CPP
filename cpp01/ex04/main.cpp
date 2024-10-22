/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:49:57 by lboudjel          #+#    #+#             */
/*   Updated: 2024/10/22 21:36:34 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"


/*

	while sur getline du fichier donner en argument (donc tant que ya qlq chose dedasn)
		while (line)
		{
			
		
		}



*/


void	opening_file(std::ifstream &filename, std::string s1, std::string s2)
{
	std::string		line;
	std::ofstream 	file_replace("file.replace");
	if (file_replace.is_open()) 
	{
		while (getline(filename, line))
		{
			int n = 0;
			while (1)
			{
				std::size_t pos_to_find = line.find(s1, n);
				if (pos_to_find == std::string::npos)
					break ;
					
				// pos_to_find
				// |alut cava
				line.erase(pos_to_find, s1.length());
				// line.erase
				// |lut cava
				line.insert(pos_to_find, s2);
				// line.insert
				// |aalut cava
				n += pos_to_find;
				// |merdesalut cava
				// |lutcava
			}
			std::cout << "tour de boucle" << std::endl;
			file_replace << line << std::endl;
		}
	}
	else
		std::cerr << "An error occured while creating the file_replace." << std::endl;
	(void)s1;
	(void)s2;
	filename.close();
	file_replace.close();
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string s1 = argv[2];
		std::string s2 = argv[3];
		std::ifstream filename(argv[1]);
		if (filename.is_open())
			opening_file(filename, s1, s2);
		else
			std::cerr << "An error occured while opening the file : " << argv[1] << std::endl;
	}
	else {
		std::cout << "Error ! 3 arguments needed : <filename>, s1 and s2." << std::endl;
		return (1);
	}
}