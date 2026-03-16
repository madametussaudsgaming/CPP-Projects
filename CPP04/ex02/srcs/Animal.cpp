/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:27:48 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/16 17:14:46 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal()
{
	std::cout<<"Animal::Default Constructor called!"<<std::endl;
	this->type="Animal";
}

Animal::Animal(std::string type)
{
	std::cout<<"Animal::String Constructor called!"<<std::endl;
	this->type=type;
}

Animal::Animal(const Animal& ori)
{
	std::cout<<"Animal::Copy Constructor called!"<<std::endl;
	this->type = ori.type;
}

Animal& Animal::operator=(const Animal& ori)
{
	std::cout<<"Animal::Copy Assignment Operator called!"<<std::endl;
	if (this == &ori)
		return (*this);
	this->type = ori.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout<<"Animal::Destructor called!"<<std::endl;
}

void Animal::makeSound() const
{
	std::cout<<"Animal::*Default sound*"<<std::endl;
}

std::string Animal::getType() const
{
	return (type);
}