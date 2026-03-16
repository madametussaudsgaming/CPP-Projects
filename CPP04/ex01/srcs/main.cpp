/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:06:23 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/16 20:50:23 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	Animal *Animals[10];
	for (int i = 0; i < 5; i++)
	{
		Animals[i] = new Cat();
	}
	for (int i = 5; i < 10; i++)
		Animals[i] = new Dog();
	for (int i = 0; i < 10; i++)
		std::cout<<Animals[i]->getType()<<std::endl;
	for (int i = 0; i < 10; i++)
		delete Animals[i];
	// for (int i = 0; i < 5; i++)
	// 	std::cout<<std::endl;
}