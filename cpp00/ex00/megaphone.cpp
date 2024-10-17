#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main (int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; argc > i; i++)
	{
		std::string str = argv[i];
		std::transform(str.begin(), str.end(), str.begin(), toupper);
		std::cout << str;
	}
	std::cout << std::endl;
	return 0;
}