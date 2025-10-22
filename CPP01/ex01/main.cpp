/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 00:35:44 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/10 00:45:46 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *Zombies = zombieHorde(5, "john");
	Zombies[0].announce();
	Zombies[1].announce();
	Zombies[2].announce();
	Zombies[3].announce();
	Zombies[4].announce();
	delete[] Zombies;
}