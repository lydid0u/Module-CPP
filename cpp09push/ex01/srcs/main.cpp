/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:24:57 by lboudjel          #+#    #+#             */
/*   Updated: 2025/03/10 23:26:46 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* a parser :
	operateur pas en dernier				OK
	lettre au milieu						OK
	nombre									OK
	operateur en 1							OK	
*/

const char *notEnoughNumberStack::what() const throw() {
	return (" not enough number in the stack to do the operation");
}

const char *ErrorOperator::what() const throw() {
	return (" operator not used correctly");
}

const char *CharIncorrect::what() const throw() {
	return (" not a digit or an operator");
}

const char *isANumber::what() const throw() {
	return (" int bigger than 9 or is a letter");
}

const char *numberLeftStack::what() const throw() {
	return (" int hasn't been used and is left in the stack");
}

const char *notEnoughArgument::what() const throw() {
	return (" not enough argument to do this operation");
}

bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

int calc(int v1, int v2, char c) {
	if (c == '*')
		return (v1 * v2);
	if (c == '+')
		return (v1 + v2);
	if (c == '-')
		return (v2 - v1);
	if (c == '/' && v1 != 0)
		return (v2 / v1);
	throw ErrorOperator();
}

int main(int argc, char **argv) {
	try {
		if (argc != 2) {
			std::cerr << IRED << "Error : Need exactly one quoted argument" << std::endl;
			return (1);
		}
		else if (!argv[1][0]) {
			std::cerr << IRED << "Error : Empty argument" << std::endl;
			return (1);
		}
		else if (strchr("+-/*", argv[1][0]))
			throw ErrorOperator();

		std::istringstream input(argv[1]);
		std::string digit;
		
		std::stack<int> mystack;
		int v1, v2, total = 0;
		
		while (input >> digit) {
			if (digit.length() != 1)
				throw isANumber();
			if (isDigit(digit[0]))
				mystack.push(digit[0] - '0');
			else if (strchr("+-/*", digit[0])) {
				if (mystack.size() < 2)
					throw notEnoughNumberStack();   
				v1 = mystack.top();
				mystack.pop();
				v2 = mystack.top();
				mystack.pop();
				
				total = calc(v1, v2, digit[0]);
				mystack.push(total);
			}
			else
				throw CharIncorrect();
		}
		if (mystack.size() != 1)
			throw numberLeftStack();
		std::cout << "total -> " << mystack.top() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << BRED << "Error :" << IRED << e.what() << RESET << std::endl;
		return (1);
	}
	return (0);
}