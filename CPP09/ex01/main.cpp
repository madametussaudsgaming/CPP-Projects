/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 08:37:09 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/30 08:40:48 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	const char *s = argv[1];
	std::string str1 = s;
	try
	{
		rpn obj(str1);
	}
	catch (const char* error) {
		std::cerr << "Error: " << error << std::endl;
	}
}