/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:06:23 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/16 17:55:35 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	// const Animal *meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();

	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// j->makeSound();
	// i->makeSound();
	// meta->makeSound();

	// delete i;
	// delete j;
	// delete meta;

	std::cout << "==== Wrong classes tests ====\n";

  // Additional tests with WrongCat
	const WrongAnimal *metaa = new WrongAnimal();
	const WrongAnimal *ii = new WrongCat();
	std::cout << ii->getType() << " " << std::endl;
	ii->makeSound(); // will output the cat sound!
	metaa->makeSound();

	delete metaa;
	delete ii;
	return (0);
}