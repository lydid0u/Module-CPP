/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:07:43 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/03 15:33:37 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) 
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
	{
		std::cout << "Error you need one argument : " << BLUE << "<./ScalarConverter + \"argument\">" << std::endl;
		return (1);
	}
	return (0);
}