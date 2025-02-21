/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:07:43 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/21 20:58:51 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

class notEnoughNumberStack : public std::exception {
    public:
        virtual const char* what() const throw();
};

const char *notEnoughNumberStack::what() const throw() {
	return (" not enough number left in the stack to do the operation");
}

class ErrorOperator : public std::exception {
    public:
        virtual const char* what() const throw();
};

const char *ErrorOperator::what() const throw() {
	return (" operator not used correctly");
}

class CharIncorrect : public std::exception {
    public:
        virtual const char* what() const throw();
};

const char *CharIncorrect::what() const throw() {
	return (" not a digit or an operator");
}

class isANumber : public std::exception {
    public:
        virtual const char* what() const throw();
};

const char *isANumber::what() const throw() {
	return (" int bigger than 9 or is a letter");
}

class numberLeftStack : public std::exception {
    public:
        virtual const char* what() const throw();
};

const char *numberLeftStack::what() const throw() {
	return (" a int hasn't been used and is left in the stack");
}

class notEnoughArgument : public std::exception {
    public:
        virtual const char* what() const throw();
};

const char *notEnoughArgument::what() const throw() {
	return (" not enough argument to do this operation");
}

std::stack<int> mystack;

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

int oneArgument(int argc, char **argv) {
	if (isDigit(argv[1][0]) && !argv[1][1]) {
		std::cout << argv[1][0] << std::endl;
		return (0);
	}
	throw notEnoughArgument();
	return (1);
}

int main(int argc, char **argv) {
	try {
		if (argc < 2) {
			std::cerr << "Error : Not enough argument" << std::endl;
			return (1);
		}
		else if (argc == 2)
			return (oneArgument(argc, argv));
		else if (!strchr("+-/*", argv[argc - 1][0]) || strchr("+-/*", argv[1][0]))
			throw ErrorOperator();
		else if (isDigit(argv[1][0]) && isDigit(argv[2][0])) {
			int v1, v2, total;
			for (int i = 1; i < argc; i++) {
				if (argv[i][1])
					throw isANumber();
				if (isDigit(argv[i][0]))
					mystack.push((argv[i][0]) - '0');
				else if (strchr("+-/*", argv[i][0])) {
					if (mystack.size() < 2)
						throw notEnoughNumberStack();
					v1 = mystack.top();
					mystack.pop();
					v2 = mystack.top();
					mystack.pop();
					total = calc(v1, v2, argv[i][0]);
					mystack.push(total);
				}
				else
					throw CharIncorrect();
			}
			if (mystack.size() != 1)
				throw numberLeftStack();
			std::cout << "total -> " << total << std::endl;		
		}
	}
	catch (std::exception &e) {
		std::cerr << BRED << "Error :" << IRED << e.what() << RESET << std::endl;
	}
}