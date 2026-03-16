/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:59:47 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/16 17:19:08 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout<<"Cat::Default Constructor called!"<<std::endl;
	this->type="Cat";
}

Cat::Cat(std::string type): Animal(type)
{
	std::cout<<"Cat::String Constructor called!"<<std::endl;
	this->type=type;
}

Cat::Cat(const Cat& ori): Animal(ori)
{
	std::cout<<"Cat::Copy Constructor called!"<<std::endl;
	this->type = ori.type;
}

Cat &Cat::operator=(const Cat& ori)
{
	std::cout<<"Cat::Copy Assignment Operator called!"<<std::endl;
	if (this == &ori)
		return (*this);
	this->type = ori.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout<<"Cat::Destructor called!"<<std::endl;
}

void Cat::makeSound() const
{
	std::cout<<"*MRRREOW!*"<<std::endl;
}