/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:49:57 by lboudjel          #+#    #+#             */
/*   Updated: 2024/10/25 17:57:49 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	opening_file(std::ifstream &filename, std::string fileReplaceName, std::string s1, std::string s2)
{
	std::string		line;
	std::ofstream 	file_replace(fileReplaceName.c_str());
	if (file_replace.is_open()) 
	{
    	std::string previous_line;
    	bool first_line = 1;
    	while (getline(filename, line))
    	{
    	    int n = 0;
    	    if (s1[n])
    	    {
    	        for (std::size_t pos_to_find = line.find(s1, n); pos_to_find != std::string::npos; pos_to_find = line.find(s1, n))
    	        {
    	            line.erase(pos_to_find, s1.length());
    	            line.insert(pos_to_find, s2);
    	            n = pos_to_find + s2.length();
    	        }
    	    }
    	    if (!first_line)
    	        file_replace << previous_line << std::endl;
    	    first_line = 0;
    	    previous_line = line;
    	}
    	file_replace << previous_line;
}
	else
		std::cerr << "An error occured while creating the file_replace." << std::endl;
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
		std::string fileReplaceName = std::string(argv[1]) + ".replace";
		if (filename.is_open())
			opening_file(filename, fileReplaceName, s1, s2);
		else
			std::cerr << "An error occured while opening the file : " << argv[1] << std::endl;
	}
	else {
		std::cout << "Error ! 3 arguments needed : <filename>, s1 and s2." << std::endl;
		return (1);
	}
}

// void	opening_file(std::ifstream &filename, std::string fileReplaceName, std::string s1, std::string s2)
// {
// 	std::string		line;
// 	std::ofstream 	file_replace(fileReplaceName.c_str());
// 	if (file_replace.is_open()) 
// 	{
// 		while (getline(filename, line))
// 		{
// 			int n = 0;
// 			if (s1[n])
// 			{
// 				for (std::size_t pos_to_find; (pos_to_find = line.find(s1, n)) && pos_to_find != std::string::npos; n = pos_to_find + s2.length())
// 				{
// 					line.erase(pos_to_find, s1.length());
// 					line.insert(pos_to_find, s2);
// 				}			
// 			}
// 			file_replace << line << std::endl;
// 		}
// 	}
// 	else
// 		std::cerr << "An error occured while creating the file_replace." << std::endl;
// 	filename.close();
// 	file_replace.close();
// }