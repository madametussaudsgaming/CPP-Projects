/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:30:40 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/28 16:46:26 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main()
{
	Data ori;
	ori.value = 42;
	ori.name = "test";

	uintptr_t raw = Serializer::serialize(&ori);
	Data* ptr = Serializer::deserialize(raw);

	std::cout << "value: " << ptr->value << std::endl;
	std::cout << "name:  " << ptr->name << std::endl;
	std::cout << "Pointers match: " << (ptr == &ori ? "true" : "false") << std::endl;
}