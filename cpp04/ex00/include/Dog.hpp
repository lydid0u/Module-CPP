/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:11:48 by lboudjel          #+#    #+#             */
/*   Updated: 2024/11/29 19:13:28 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Dog.hpp
#ifndef Dog_HPP
#define Dog_HPP

class Dog {
public:
	Dog();

	Dog(const Dog& other);

	Dog& operator=(const Dog& other);

	~Dog();

private:
	std::string _type;
};

#endif // Dog_HPP