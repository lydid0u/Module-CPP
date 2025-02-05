#include "iter.hpp"

void print_int(int& value) {
    std::cout << value << std::endl;
}

void insert_str(std::string& str) {
	std::cout << str.insert(0, "iter ") << std::endl;
	
}


int main() {
    std::cout << GREEN << "int tab:" << RESET << std::endl;
    int int_tab[] = {1, 2, 3, 4, 5};
	iter(int_tab, 5, print_int);
    std::cout << std::endl;
    
    std::cout << GREEN << "string tab:" << RESET << std::endl;
	std::string string_tab[] = {"UN", "DEUX", "TROis", "quatre"};
	iter(string_tab, 4, insert_str);
    
	return 0;
}