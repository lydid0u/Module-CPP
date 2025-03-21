/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:10:52 by lboudjel          #+#    #+#             */
/*   Updated: 2024/10/17 19:09:22 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class	Zombie {
	private:
	std::string name;
	
	public:
	Zombie(void);
	Zombie(std::string zombie_name);
	~Zombie(void);
	void announce(void);
	std::string GetName();
	void	SetName(std::string);

};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif