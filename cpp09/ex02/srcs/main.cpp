#include "PMergeMe.hpp"


int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		try {
			PmergeMe(argv + 1);
		}
		catch (const std::exception &e) {
			std::cout << IRED << "Error: " << e.what() << RESET << std::endl;
		}
	}
	else
		std::cout << "Invalid numbers of arguments!" << std::endl;
	return (0);
}