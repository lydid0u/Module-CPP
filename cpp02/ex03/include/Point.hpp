/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:13:23 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/08 20:27:39 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		static const int Bits = 8;

	public:
		Fixed();
		Fixed(const int copy);
		Fixed(const float copy);
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		~Fixed();
}

#endif