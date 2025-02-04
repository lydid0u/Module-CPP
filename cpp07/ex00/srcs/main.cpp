#include "whatever.hpp"

int main()
{
	std::cout << YELLOW << "SWAP :\n" << RESET;

	std::string str_1 = "lydia";
	std::string str_2 = "saber";
	
	std::cout << BLUE << "\tbefore swap template:" << RESET << std::endl;
	std::cout << "str_1 : " << str_1 << ", str_2 :" << str_2 << std::endl;
	swap(str_1, str_2);

	std::cout << BLUE << "\tafter swap template:" << RESET << std::endl;
	std::cout << "str_1 : " << str_1 << ", str_2 :" << str_2 << std::endl;
	std::cout << std::endl;
	

	std::cout << YELLOW << "MIN :\n" << RESET;

	std::cout << ::min(6, 12) << std::endl;
	std::cout << ::min(0.6, 0.12) << std::endl;
	std::cout << ::min('a', 'z') << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "MAX :\n" << RESET;

	std::cout << ::max(6, 12) << std::endl;
	std::cout << ::max('a', 'z') << std::endl;
	std::cout << ::max(42.0f, 10.5f) << std::endl;
}