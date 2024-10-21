/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:05:01 by lboudjel          #+#    #+#             */
/*   Updated: 2024/10/21 17:38:23 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	msg_lvl(std::string level)
{
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