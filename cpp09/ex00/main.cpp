/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:20:55 by fcaldas-          #+#    #+#             */
/*   Updated: 2025/07/11 19:20:56 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "colors.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED "Usage example: " << argv[0] << " <filename>" << RST << std::endl;
		return (1);
	}
	BitcoinExchange	btc;
	if (!btc.dbLoad("data.csv"))
		return (1);
	btc.fileProcess(argv[1]);
	return (0);
}