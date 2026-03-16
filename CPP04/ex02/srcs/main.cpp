/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:06:23 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/16 20:54:11 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	Animal *Kaizer = new Cat;
	Kaizer->makeSound();
	delete Kaizer;
	// Animal *AnimalKaizer = new Animal;
	//as you can see this is not allowed

}