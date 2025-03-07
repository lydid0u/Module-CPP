/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:05:01 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/30 16:26:27 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	msg_lvl(std::string level)
{
	// std::string a[5] = "DEBUG", "INFO", "WARNING", "ERROR"};
	if (level == "DEBUG")
		return (1);
	if (level == "INFO")
		return (2);
	if (level == "WARNING")
		return (3);
	if (level == "ERROR")
		return (4);
	return (0);
}

int	main()
{
	Harl	callingHarl;
	
	callingHarl.complain("DEBUG");
	std::cout << std::endl;
	callingHarl.complain("INFO");
	std::cout << std::endl;
	callingHarl.complain("WARNING");
	std::cout << std::endl;	
	callingHarl.complain("ERROR");
	std::cout << std::endl;	
	callingHarl.complain("SDLF");
}