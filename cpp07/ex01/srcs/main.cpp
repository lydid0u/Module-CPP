#include "iter.hpp"

void print(int& value) {
    std::cout << value << std::endl;
}
// int main() {
//     std::string tab[] = { "AAA", "VDVFD", "SDFDF", "fdsgd" };

//     iter(tab, 4, );
// }


int main() {
    int arr[] = {1, 2, 3, 4, 5};

    iter(arr, 5, print);

    return 0;
}
