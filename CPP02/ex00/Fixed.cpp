/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:15:01 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/28 16:25:22 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	fp_Num_Val = 0;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

Fixed& Fixed::operator=(const Fixed& variables) {
	std::cout<<"Copy assignment operator called"<<std::endl;
	this->fp_Num_Val = variables.getRawBits();
	return (*this);
}

Fixed::Fixed(Fixed& variables) {
	std::cout<<"Copy constructor called"<<std::endl;
	*this = variables;
}

int	Fixed::getRawBits( void ) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return (fp_Num_Val);
}

void Fixed::setRawBits( int const raw ) {	fp_Num_Val = raw;	}