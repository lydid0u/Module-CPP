/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:20:22 by lboudjel          #+#    #+#             */
/*   Updated: 2025/01/30 16:22:34 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug(void){
	std::cout << "DEBUG\n" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void Harl::info(void){
	std::cout << "INFO\n" << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::warning(void){
	std::cout << "WARNING\n" << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void){
	std::cout << "ERROR\n" << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*ptr)() = NULL;
	int lvl = msg_lvl(level);
	if (lvl == 0)
	{
		std::cout << "Oops: [" << level << "] unknown level !\n";
		return ;
	}
	Harl	harl2;

	switch(lvl){
		case 1: ptr = &Harl::debug;
			break;
		case 2: ptr = &Harl::info;
			break;
		case 3: ptr = &Harl::warning;
			break;
		case 4: ptr = &Harl::error;
			break;	
	}
	(harl2.*ptr)();
}

