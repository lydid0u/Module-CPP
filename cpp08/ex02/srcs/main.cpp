/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:07:43 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/11 15:10:22 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << BCYAN << " TESTING WITH STACK " << RESET << std::endl;
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << IYELLOW << "Value at the top of the stack : " << IBLUE << mstack.top() << RESET << std::endl;
	
	mstack.pop();
	
	std::cout << IYELLOW << "Mutant stack size : " << IBLUE << mstack.size() << RESET << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	std::cout << std::endl << IGREEN << "Printing while iterating on the stack : " << RESET << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	
    // -----------------------------------------------------// 
	
	std::cout << std::endl << BCYAN << " TESTING WITH LIST " << RESET << std::endl;

    std::list<int> mlist;
    
	mlist.push_back(5);
    mlist.push_back(17);
	
	std::cout << IYELLOW << "Value at the top of the list : " << IBLUE  << mlist.back() << std::endl;
   
    mlist.pop_back();
    
	std::cout << IYELLOW << "List size : " << IBLUE << mlist.size() << RESET << std::endl;
	
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
	
    std::list<int>::iterator itt = mlist.begin();
    std::list<int>::iterator itte = mlist.end();
	
    ++itt;
    --itt;
	std::cout << std::endl << IGREEN << "Printing while iterating on the list : " << RESET << std::endl;
    while(itt != itte)
    {
        std::cout << *itt << std::endl;
        ++itt;
    }
    std::list<int> l(mlist);
	return 0;
}