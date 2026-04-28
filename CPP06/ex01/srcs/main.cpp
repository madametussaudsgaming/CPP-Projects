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
	ori.data = 10;
	std::cout<<ori.data<<std::endl;
	uintptr_t middle = Serializer::serialize(&ori);
	Data* final = Serializer::deserialize(middle);
	std::cout<<final->data<<std::endl;
	std::cout << "Pointers match: " << (final == &ori ? "true" : "false") << std::endl;
}