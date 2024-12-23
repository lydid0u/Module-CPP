#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Default Animal constructor has been created.\n";
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called\n";
}

std::string Animal::getType() const
{
    return (_type);
}
