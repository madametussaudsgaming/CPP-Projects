/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 15:05:54 by rpadasia          #+#    #+#             */
/*   Updated: 2026/06/06 15:47:24 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printChar(char c) {
	std::cout << c << std::endl;
}

void printInt(int c) {
	std::cout << std::endl << c;
}

int main() {
	std::string arr = "READ THIS!";
	iter(&arr[0], arr.size(), printChar);
	int arr2[] = {1, 2, 3, 4, 5};
	iter(arr2, sizeof(arr2) / sizeof(arr2[0]), printInt);
	std::cout << std::endl;
}