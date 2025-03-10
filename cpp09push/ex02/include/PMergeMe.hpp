/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:44:17 by lboudjel          #+#    #+#             */
/*   Updated: 2025/03/06 23:04:13 by lboudjel         ###   ########.fr       */
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
		template <typename Container>
		void binaryInsertSort(Container &mainContainer, const std::vector<int> &smallerValues, const std::vector<int> &biggerValuesForPosition);
		template <typename Container>
		void createAndSortPairs(Container &container, Container &mainContainer, std::vector<int> &smallerValues, std::vector<int> &biggerValuesForPosition, int &oddNumber, bool &hasOddNumber);
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