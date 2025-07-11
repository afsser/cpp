/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:21:05 by fcaldas-          #+#    #+#             */
/*   Updated: 2025/07/11 20:38:24 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "colors.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED "Usage example: " YEL << argv[0] << " <expression>" RST << std::endl;
		return (1);
	}
	RPN rpn(argv[1]);
	if (!rpn.parseExpression()) {
		std::cerr << RED "Error: Invalid expression." RST << std::endl;
		std::cerr << YEL "You need at least two numbers and one operator." RST << std::endl;
		std::cerr << YEL "You need at least one number for each operator plus one." RST << std::endl; 
		std::cerr << ORG "Operators: <+> <-> <*> </>" RST << std::endl;
		std::cerr << ORG "Numbers: 0 to 9" RST << std::endl;
		std::cerr << YEL "Example:" BOLD " \"3 4 + 2 * 3 +\"" RST << std::endl;
		std::cerr << YEL "This will calculate:" BOLD " \"(3 + 4) * 2 + 3\"" RST << std::endl;
		return (1);
	}
	if (!rpn.calculate())
		return (1);
	return (0);
}
