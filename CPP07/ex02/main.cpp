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
#include <stdio.h>


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
		int numbers[] = {1, 2, 3, 4, 5};
		Array<char> obj(5);
		for (int i = 0; i < 5; i++)
		{
			obj[i] = numbers[i];
			std::cout << "Index " << i << " = ";
			printf("%d\n", obj[i]);
		}
		obj[2] = 2;
		std::cout << "Index 2 = ";
		printf("%d\n", obj[2]);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}