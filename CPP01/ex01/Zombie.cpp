/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:50:28 by rpadasia          #+#    #+#             */
/*   Updated: 2025/11/21 18:29:14 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string n)
{
	setName(n);
	announce();
}

Zombie::Zombie(Zombie& variables) {
	std::cout<<"Copy constructor called"<<std::endl;
	*this = variables;
}

Zombie& Zombie::operator=(const Zombie& variables) {
	std::cout<<"Copy assignment operator called"<<std::endl;
	this->name = variables.name;
	return (*this);
}


Zombie::~Zombie() {std::cout<<name<<" was destroyed."<<std::endl;}

void	Zombie::announce(void) { std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

void	Zombie::setName(std::string n) { name = n; }

#endif