/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:21:11 by fcaldas-          #+#    #+#             */
/*   Updated: 2025/07/12 23:12:09 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>

class RPN {
private:
	std::string 		_expression;
	std::stack<long>	_stack;
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
public:
	RPN(const std::string &expression);
	~RPN();
	bool parseExpression();
	bool calculate() const;
};

#endif