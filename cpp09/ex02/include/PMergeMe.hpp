/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:44:17 by lboudjel          #+#    #+#             */
/*   Updated: 2025/03/05 22:06:16 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include "colors.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <ctime>

class PmergeMe {
	public:
		PmergeMe(char **argv);
		~PmergeMe();
		template <typename Container>
		void 	algorithm(char **nbr, Container &container, std::clock_t &start, std::clock_t &end);
		template <typename Container>
		void	fordJohnsonSort(Container &container);

	private:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe&	operator=(const PmergeMe &other);

		std::vector<int> vector;
		std::clock_t	vectorClockStart;
		std::clock_t	vectorClockEnd;

		std::deque<int> deque;
		std::clock_t	dequeClockStart;
		std::clock_t	dequeClockEnd;
};

void	parsing(char **av);
template <typename T>
void	printRange(const T &beforeContainer, bool before);

# endif