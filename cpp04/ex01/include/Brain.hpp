/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:30:26 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/30 01:21:16 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Brain.hpp
#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();
		void		setIdea(int n, std::string idea);
		std::string	getIdea(int n);
};


#endif