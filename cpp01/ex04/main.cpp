/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:49:57 by lboudjel          #+#    #+#             */
/*   Updated: 2024/10/19 18:57:27 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string filename = argv[1];
		std::string s1 = argv[2];
		std::string s2 = argv[3];
		
		std::cout << filename << " " << s1 << " " << s2 << " " << std::endl;
	}
	else{
		std::cout << "Error ! 3 arguments needed : <filename>, s1 and s2." << std::endl;
		return (1);
	}
}