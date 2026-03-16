/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:25:34 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/16 17:33:32 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout<<"WrongAnimal::Default Constructor called!"<<std::endl;
	this->type="WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout<<"WrongAnimal::String Constructor called!"<<std::endl;
	this->type=type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& ori)
{
	std::cout<<"WrongAnimal::Copy Constructor called!"<<std::endl;
	this->type = ori.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ori)
{
	std::cout<<"WrongAnimal::Copy Assignment Operator called!"<<std::endl;
	if (this == &ori)
		return (*this);
	this->type = ori.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout<<"WrongAnimal::Destructor called!"<<std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout<<"WrongAnimal::I'm... uncanny mango phonk."<<std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}