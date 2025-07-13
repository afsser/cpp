/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:20:17 by fcaldas-          #+#    #+#             */
/*   Updated: 2025/07/12 23:39:01 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include "colors.hpp"


RPN::RPN(const std::string &expression) : _expression(expression) {}

RPN::~RPN() {}

static bool isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::parseExpression() {
	if (_expression.empty()) {
		std::cerr << RED "Error: Input is empty." RST << std::endl;
		return false;
	}
	for (size_t i = 0; i < _expression.length(); ++i) {
		char c = _expression.c_str()[i];
		if (c == ' ')
			continue ;
		if (!isdigit(c) && !isOperator(c)) {
			return false;
		}
		if (isdigit(c) && i < _expression.length() - 1 && isdigit(_expression.c_str()[i + 1])) {
			return false;
		}
	}
	return true;
}

bool RPN::calculate() const {
	int		result = 0;
	int		i = 0;
	std::stack<long> mt = this->_stack;
	std::string expr = this->_expression;
	while (!expr.empty())
	{
		if (expr.c_str()[i] == ' '){
			expr.erase(i, 1);
			continue ;
		}
		if (isdigit(expr.c_str()[i])) {
			mt.push(expr.c_str()[i] - '0');
			expr.erase(i, 1);
			continue ;
		}
		if (isOperator(expr.c_str()[i])) {
			if (mt.size() < 2) {
				std::cerr << RED "Error: Invalid Expression: Not enough digits for operation." RST << std::endl;
				return false;
			}
			int b = mt.top();
			mt.pop();
			int a = mt.top();
			mt.pop();
			switch (expr.c_str()[i]) {
				case '+':
					result = a + b;
					break;
				case '-':
					result = a - b;
					break;
				case '*':
					result = a * b;
					break;
				case '/':
					if (b == 0 || a == 0) {
						std::cerr << RED "Error: Division by zero." RST << std::endl;
						return false;
					}
					result = a / b;
					break;
				default:
					std::cerr << RED "Error: Unknown operator." RST << std::endl;
					return false;
			}
			mt.push(result);
			expr.erase(i, 1);
			continue ;
		}
		i++;
	}
	if (mt.size() != 1) {
		std::cerr << RED "Error: Invalid expression: Not enough operators." RST << std::endl;
		return false;
	}
	result = mt.top();
	mt.pop();
	if (!mt.empty()) {
		std::cerr << RED "Error: Stack should be empty after calculation." RST << std::endl;
		return false;
	}
	std::cout << YEL "Result: " BLU << result << RST << std::endl;
	return true;
}
