/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:03:32 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/16 20:50:02 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout<<"Dog::Default Constructor called!"<<std::endl;
	this->dogBrain = new Brain();
	this->type="Dog";
}

Dog::Dog(const Dog& ori): Animal(ori)
{
	std::cout<<"Dog::Copy Constructor called!"<<std::endl;
	this->type = ori.type;
	this->dogBrain = new Brain(*ori.dogBrain);
}

Dog &Dog::operator=(const Dog& ori)
{
	std::cout<<"Dog::Copy Assignment Operator called!"<<std::endl;
	if (this == &ori)
		return (*this);
	this->type = ori.type;
	this->dogBrain = new Brain(*ori.dogBrain);
	return (*this);
}

Dog::~Dog()
{
	delete this->dogBrain;
	std::cout<<"Dog::Destructor called!"<<std::endl;
}

void Dog::makeSound() const
{
	std::cout<<"*RRRRRGHWUOOF!*"<<std::endl;
}