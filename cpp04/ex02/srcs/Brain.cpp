/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:16:52 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/30 01:18:40 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Copy Brain constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Copy Brain assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}
Brain::~Brain() {
	std::cout << "Brain Destructor called" << std::endl;
}

void	Brain::setIdea(int n, std::string idea)
{
	ideas[n] = idea;
}

std::string	Brain::getIdea(int n)
{
	return (ideas[n]);
}