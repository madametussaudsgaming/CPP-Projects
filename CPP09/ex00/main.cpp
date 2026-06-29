/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:39:58 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/28 18:43:12 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	try {
		BitcoinExchange btc;
		btc.processInput(argv[1]);
	}
	catch (std::string& error) {
		std::cerr << "Error: " << error << std::endl;
	}
	return (0);

}