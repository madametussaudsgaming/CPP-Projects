/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:06:57 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/06 16:59:24 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	try {
		char abc[] = {'a', 'b', 'c', 'd'};
		Array<char> obj(4);
		for (int i = 0; i < 4; i++)
		{
			obj[i] = abc[i];
			std::cout << "Index " << i << " = " << obj[i] << std::endl;
		}
		obj[2] = 'z';
		std::cout << "Index 2 = " << obj[2] << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Array<int> obj(5);
		for (int i = 0; i < 5; i++)
			obj[i] = i + 1;
		Array<int> copy(obj);
		copy[2] = 99;
		std::cout << "original[2] = " << obj[2] << " (should be 3)" << std::endl;
		std::cout << "copy[2]     = " << copy[2] << " (should be 99)" << std::endl;
		Array<int> assigned;
		assigned = obj;
		assigned[0] = 42;
		std::cout << "original[0] = " << obj[0] << " (should be 1)" << std::endl;
		std::cout << "assigned[0] = " << assigned[0] << " (should be 42)" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Array<int> obj(3);
		obj[5];
	}
	catch (const std::exception &e) {
		std::cout << "Out of bounds: " << e.what() << std::endl;
	}
}