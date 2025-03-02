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
		template <typename Iterator>
		void	merge(Iterator start, Iterator end);

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