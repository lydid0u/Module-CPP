/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:05:01 by lboudjel          #+#    #+#             */
/*   Updated: 2024/10/21 18:55:22 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	std::string level;
	Harl	callingHarl;
	
	if (argc != 2)
	{
		std::cout << "Error: You need 2 arguments.\n";
		return (1);
	}
	else
	{
		level = argv[1];
		callingHarl.complain(level);
	}
}