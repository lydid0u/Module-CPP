/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                     		:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:33:55 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/03 19:25:06 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "ABC.hpp"

Base::~Base() {
		std::cout << "Base destructor called" << std::endl;
}

Base	*generate() {
	std::srand(std::time(0));

	if (std::rand() % 3 == 0)
		return (new A);
	else if (std::rand() % 3 == 1)
		return (new B);
	else
		return (new C);

	return (NULL);
}

void	identify(Base *ptr)
{
    if (ptr == NULL) {
        std::cout << "Null pointer" << std::endl;
        return;
    }

    if (dynamic_cast<A*>(ptr) != NULL)
        std::cout << "Pointer A" << std::endl;
    else if (dynamic_cast<B*>(ptr) != NULL)
        std::cout << "Pointer B" << std::endl;
    else if (dynamic_cast<C*>(ptr) != NULL)
        std::cout << "Pointer C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		if (&dynamic_cast<A&>(p))
		{
			std::cout << "Pointer A" << std::endl;
			return;
		}
	}
	catch(const std::exception& e) {
	}

	try
	{
		if (&dynamic_cast<B&>(p))
		{
			std::cout << "Pointer B" << std::endl;
			return;
		}
	}
	catch(const std::exception& e) {
	}
	
	try
	{
		if (&dynamic_cast<C&>(p))
		{
			std::cout << "Pointer C" << std::endl;
			return;
		}
	}
	catch(const std::exception& e){
	}

	std::cout << "Unknown type" << std::endl;
}
