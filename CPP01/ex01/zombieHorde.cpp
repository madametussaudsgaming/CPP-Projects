/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 00:30:12 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/10 00:43:52 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombieArray;
    zombieArray = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombieArray[i].setName(name);
	}
	return (zombieArray);
}