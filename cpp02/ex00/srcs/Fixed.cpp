#include "../include/Fixed.hpp"

Fixed::Fixed()
{
    ValueFixedPoint = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    ValueFixedPoint = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    if (this != &copy){
        std::cout << "Copy assignement called" << std::endl;
        ValueFixedPoint = copy.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called" << std::endl;
    return (ValueFixedPoint);
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    ValueFixedPoint = raw;
}