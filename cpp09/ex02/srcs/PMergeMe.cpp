#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(char **argv) {
	std::vector<int> beforeContainer;
	parsing(argv);

	for (int i = 0; argv[i]; i++)
		beforeContainer.push_back(atoi(argv[i]));
	printRange(beforeContainer, true);
	
	//calling algorithm with vector container
	algorithm(argv, vector, vectorClockStart, vectorClockEnd);
	//calling algorithm with deque container
	algorithm(argv, deque, dequeClockStart, dequeClockEnd);

	printRange(vector, false);
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << vectorClockEnd - vectorClockStart << " us" << std::endl;
	std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " << dequeClockEnd - dequeClockStart << " us" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		vector = other.vector;
		deque = other.deque;
		vectorClockStart = other.vectorClockStart;
		dequeClockStart = other.dequeClockStart;
		vectorClockEnd = other.vectorClockEnd;
		dequeClockEnd = other.dequeClockEnd;
	}
	return (*this);
}

void	parsing(char **nbr) {
	for (int i = 0; nbr[i]; i++) {
		char *endptr;
		long nb = strtol(nbr[i], &endptr, 10);
		if (*endptr != '\0')
	    	throw std::invalid_argument("invalid input, value is not an int -> " + std::string(nbr[i]));
      	if (nb < 0)
	    	throw std::invalid_argument("not a positive number -> " + std::string(nbr[i]));
		if (nb > INT_MAX || nb < INT_MIN)
	    	throw std::invalid_argument("number not in the range of an int  -> " + std::string(nbr[i]));
    }

	for (int i = 0; nbr[i]; i++) {
		long nb = strtol(nbr[i], NULL, 10);
		for (int j = i + 1; nbr[j]; j++) {
			if (nb == strtol(nbr[j], NULL, 10))
				throw std::invalid_argument("number found twice -> " + std::string(nbr[j]));
		}
	}
}

template <typename T>
void	printRange(const T &container, bool before) {
	int i;
	if (before == true)
		std::cout << "Before : ";
	else
		std::cout << "After : ";
	for (i = 0; i < container.size() - 1; i++)
		std::cout << container[i] << " ";
	std::cout << container[i] << std::endl;
}

template <typename Container>
void PmergeMe::algorithm(char **nbr, Container &container, std::clock_t &start, std::clock_t &end) {
    start = std::clock();
    for (int i = 0; nbr[i]; i++)
		container.push_back(atoi(nbr[i]));
    merge(container.begin(), container.end());
    end = std::clock();
}

template <typename Iterator>
void PmergeMe::merge(Iterator start, Iterator end) {
    if (std::distance(start, end) < 2)
        return;
    Iterator middle = start;
    std::advance(middle, (std::distance(start, end) / 2));
    merge(start, middle);
    merge(middle, end);
    std::inplace_merge(start, middle, end);
}