/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:50:28 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/07 23:59:14 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string n)
{
	setName(n);
	announce();
}

Zombie::~Zombie() {std::cout<<name<<" was destroyed."<<std::endl;}

void	Zombie::announce(void) { std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

void	Zombie::setName(std::string n) { name = n; }