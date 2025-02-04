#include "whatever.hpp"

int main()
{
	std::cout << YELLOW << "SWAP :\n" << RESET;

	std::string str_1 = "lydia";
	std::string str_2 = "saber";
	
	std::cout << "before swapping :" << std::endl;
	std::cout << "str_1 : " << str_1 << ", str_2 :" << str_2 << std::endl;
	// swap(str_1, str_2);

	std::cout << "after swapping :" << std::endl;
	std::cout << str_1 << ", " << str_2 << std::endl;
	std::cout << std::endl;
	

	std::cout << YELLOW << "MIN :\n" << RESET;

	std::cout << ::min(6, 12) << std::endl;
	std::cout << ::min('a', 'z') << std::endl;
	std::cout << ::min(str_1, str_2) << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "MAX :\n" << RESET;

	std::cout << ::max(6, 12) << std::endl;
	std::cout << ::max('a', 'z') << std::endl;
	std::cout << ::max(0.0001, 12.5) << std::endl;
	std::cout << ::max(str_1, str_2) << std::endl;

}