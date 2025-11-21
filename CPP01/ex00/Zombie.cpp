/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:50:28 by rpadasia          #+#    #+#             */
/*   Updated: 2025/11/21 17:30:42 by rpadasia         ###   ########.fr       */
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

Zombie::Zombie(Zombie& variables) {
	std::cout<<"Copy constructor called"<<std::endl;
	*this = variables;
}

Zombie& Zombie::operator=(const Zombie& variables) {
	std::cout<<"Copy assignment operator called"<<std::endl;
	this->name = variables.name;
	return (*this);
}

void	Zombie::announce(void) { std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

void	Zombie::setName(std::string n) { name = n; }