#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int ValueFixedPoint;
    static const int Bits = 8;
public:
    Fixed(const int aFloat);
    Fixed(const Fixed& copy);
    Fixed& operator=(const Fixed& copy);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;
};




#endif