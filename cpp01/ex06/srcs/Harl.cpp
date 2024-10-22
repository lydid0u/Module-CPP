/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:20:22 by lboudjel          #+#    #+#             */
/*   Updated: 2024/10/22 15:17:18 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug(void){
	std::cout << "[ DEBUG ]\n" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void Harl::info(void){
	std::cout << "[ INFO ]\n" << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::warning(void){
	std::cout << "[ WARNING ]\n" << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void){
	std::cout << "[ ERROR ]\n" << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

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


void Harl::complain(std::string level)
{
	Harl	harl2;
	int lvl = msg_lvl(level);

	switch(lvl)
	{
		case 1: harl2.debug();
			std::cout << std::endl;
		case 2: harl2.info();
			std::cout << std::endl;
		case 3: harl2.warning();
			std::cout << std::endl;
		case 4: harl2.error();
			std::cout << std::endl;
			break;
		default : std::cout << "[ Probably complaining about insignificant problems ]" << std::endl; 
			break;
	}
	if (lvl == 0)
		exit(0);
	
}

