/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   Fixed.cpp										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/29 15:36:04 by lboudjel		  #+#	#+#			 */
/*   Updated: 2024/10/29 17:05:09 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../include/Fixed.hpp"

//---------------- CONSTRUCTEUR - DESTRUCTEUR ----------------//

Fixed::Fixed(){
	ValueFixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value){
	ValueFixedPoint = value << Bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value){
	ValueFixedPoint = roundf(value * (1 << Bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy){
	std::cout << "Copy constructor called" << std::endl;
	ValueFixedPoint = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy){
	if (this != &copy){
		std::cout << "Copy assignement operator called" << std::endl;
		ValueFixedPoint = copy.getRawBits();
	}
	return *this;
}

//------------------------------------------------------------//

int Fixed::getRawBits() const{
	return (ValueFixedPoint);
}

void Fixed::setRawBits(int const raw){
	ValueFixedPoint = raw;
}

int Fixed::toInt(void) const{
	return (ValueFixedPoint >> Bits);
}

float Fixed::toFloat(void) const{
	float value = (float)ValueFixedPoint / (1 << Bits);
	return (value);
}

//----------------- SURCHARGE DES OPERATEURS -----------------//

std::ostream &operator<<(std::ostream &out, const Fixed &value){
	out << value.toFloat();
	return out;
}

Fixed	Fixed::operator+(const Fixed &value) const{
	return Fixed((ValueFixedPoint + value.ValueFixedPoint) >> Bits);
}

Fixed	Fixed::operator-(const Fixed &value) const{
	return Fixed((ValueFixedPoint - value.ValueFixedPoint) >> Bits);
}

Fixed	Fixed::operator*(Fixed const &value) const
{
	Fixed tmp;
	tmp.setRawBits(ValueFixedPoint * value.ValueFixedPoint >> Bits);
	return (tmp);
}

Fixed	Fixed::operator/(Fixed const &value) const
{
	Fixed tmp;
	tmp.setRawBits(ValueFixedPoint / value.toFloat());
	return (tmp);
}
