/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:27:30 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/16 17:29:06 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout<<"WrongCat::Default Constructor called!"<<std::endl;
	this->type="WrongCat";
}

WrongCat::WrongCat(std::string type): WrongAnimal(type)
{
	std::cout<<"WrongCat::String Constructor called!"<<std::endl;
	this->type=type;
}

WrongCat::WrongCat(const WrongCat& ori): WrongAnimal(ori)
{
	std::cout<<"WrongCat::Copy Constructor called!"<<std::endl;
	this->type = ori.type;
}

WrongCat &WrongCat::operator=(const WrongCat& ori)
{
	std::cout<<"WrongCat::Copy Assignment Operator called!"<<std::endl;
	if (this == &ori)
		return (*this);
	this->type = ori.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout<<"Cat::Destructor called!"<<std::endl;
}

void WrongCat::makeSound() const
{
	std::cout<<"*MRRREOW!* (but uncanny mango phonk)"<<std::endl;
}
