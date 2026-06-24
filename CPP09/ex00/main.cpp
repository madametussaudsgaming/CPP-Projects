/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:39:58 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/24 20:39:34 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if(argc != 2)
    {
        std::cout << "One Argument Only" << std::endl;
        return (1);
    }
	try {
		BitcoinExchange btc;
	}
	catch(std::string error) {

	}

}