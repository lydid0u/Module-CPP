/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   Fixed.hpp										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/29 14:57:33 by lboudjel		  #+#	#+#			 */
/*   Updated: 2024/10/29 15:42:23 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int ValueFixedPoint;
	static const int Bits = 8;

public:
	Fixed();
	Fixed(const int copy);
	Fixed(const float copy);
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);
	~Fixed();

	Fixed	operator+(const Fixed &value) const;
	Fixed	operator-(const Fixed &value) const;
	Fixed	operator*(const Fixed &value) const;
	Fixed	operator/(const Fixed &value) const;

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &value);

#endif