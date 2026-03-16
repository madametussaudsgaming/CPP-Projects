/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:59:47 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/16 20:49:31 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout<<"Cat::Default Constructor called!"<<std::endl;
	this->catBrain = new Brain();
	this->type="Cat";
}

Cat::Cat(const Cat& ori): Animal(ori)
{
	std::cout<<"Cat::Copy Constructor called!"<<std::endl;
	this->type = ori.type;
	this->catBrain = new Brain(*ori.catBrain);
}

Cat &Cat::operator=(const Cat& ori)
{
	std::cout<<"Cat::Copy Assignment Operator called!"<<std::endl;
	if (this == &ori)
		return (*this);
	this->type = ori.type;
	this->catBrain = new Brain(*ori.catBrain);
	return (*this);
}

Cat::~Cat()
{
	delete this->catBrain;
	std::cout<<"Cat::Destructor called!"<<std::endl;
}

void Cat::makeSound() const
{
	std::cout<<"*MRRREOW!*"<<std::endl;
}