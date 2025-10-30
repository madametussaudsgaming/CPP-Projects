/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:15:01 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/28 21:31:44 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*CONSTRUCTORS*/
Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	fp_Num_Val = 0;
}

Fixed::Fixed(const int param)
{
	std::cout<<"Int constructor called"<<std::endl;
	fp_Num_Val = param << frac_Bits;
}

Fixed::Fixed(const float param)
{
	std::cout<<"Float constructor called"<<std::endl;
	fp_Num_Val = param * (pow(2, frac_Bits));
}

/*COPY CONSTRUCTOR*/
Fixed::Fixed(const Fixed& variables) {
	std::cout<<"Copy constructor called"<<std::endl;
	*this = variables;
}

/*DESTURCTOR*/
Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}




/*EVIL MEMBER FUNCTIONS*/

int	Fixed::getRawBits( void ) const
{
	// std::cout<<"getRawBits member function called"<<std::endl;
	return (fp_Num_Val);
}

void Fixed::setRawBits( int const raw )
{
	fp_Num_Val = raw;
}

float Fixed::toFloat( void ) const
{
	return (fp_Num_Val / (pow(2, frac_Bits)));
}

int	Fixed::toInt( void ) const
{
	return (fp_Num_Val >> frac_Bits);
}

/*OVERLOADERS*/

Fixed& Fixed::operator=(const Fixed& variables) {
	std::cout<<"Copy assignment operator called"<<std::endl;
	this->fp_Num_Val = variables.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Fixed& fp_Num)
{
	out << fp_Num.toFloat();
	return (out);
}