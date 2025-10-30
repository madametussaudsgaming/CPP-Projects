/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:15:01 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/30 18:19:10 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*CONSTRUCTORS*/
Fixed::Fixed()
{
	// std::cout<<"Default constructor called"<<std::endl;
	fp_Num_Val = 0;
}

Fixed::Fixed(const int param)
{
	// std::cout<<"Integer constructor called"<<std::endl;
	fp_Num_Val = (param << frac_Bits);
}

/*param * 256.0*/
Fixed::Fixed(const float param)
{
	// std::cout<<"Float constructor called"<<std::endl;
	fp_Num_Val = roundf(param * float(1 << frac_Bits));
}

/*COPY CONSTRUCTOR*/
Fixed::Fixed(const Fixed& variables) {
	// std::cout<<"Copy constructor called"<<std::endl;
	*this = variables;
}

/*DESTURCTOR*/
Fixed::~Fixed()
{
	// std::cout<<"Destructor called"<<std::endl;
}




/*EVIL MEMBER FUNCTIONS*/

int	Fixed::getRawBits( void ) const
{
	return (fp_Num_Val);
}

void Fixed::setRawBits( int const raw )
{
	fp_Num_Val = raw;
}

float Fixed::toFloat( void ) const
{
	return (float(fp_Num_Val / (pow(2, frac_Bits))));
}

int	Fixed::toInt( void ) const
{
	return (fp_Num_Val >> frac_Bits);
}

Fixed& Fixed::min(Fixed& fp1, Fixed& fp2)
{
	return (fp1 < fp2 ? fp1 : fp2);
}

const Fixed& Fixed::min(const Fixed& fp1, const Fixed& fp2)
{
	return (fp1 < fp2 ? fp1 : fp2);
}

Fixed& Fixed::max(Fixed& fp1, Fixed& fp2)
{
	return (fp1 > fp2 ? fp1 : fp2);
}

const Fixed& Fixed::max(const Fixed& fp1, const Fixed& fp2)
{
	return (fp1 > fp2 ? fp1 : fp2);
}

/*FIVE TRILLION OVERLOADERS TO*/

Fixed& Fixed::operator=(const Fixed& variables)
{
	// std::cout<<"Copy assignment operator called"<<std::endl;
	this->fp_Num_Val = variables.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Fixed& fp_Num)
{
	out << fp_Num.toFloat();
	return (out);
}

int Fixed::operator==(const Fixed& fp) const
{
	return (fp_Num_Val == fp.fp_Num_Val);
}

int Fixed::operator>=(const Fixed& fp) const
{
	return (fp_Num_Val >= fp.fp_Num_Val);
}

int Fixed::operator<=(const Fixed& fp) const
{
	return (fp_Num_Val <= fp.fp_Num_Val);
}

int Fixed::operator>(const Fixed& fp) const
{
	return (fp_Num_Val > fp.fp_Num_Val);
}

int Fixed::operator<(const Fixed& fp) const
{
	return (fp_Num_Val < fp.fp_Num_Val);
}

int Fixed::operator!=(const Fixed& fp) const
{
	return (fp_Num_Val != fp.fp_Num_Val);
}

Fixed Fixed::operator+(const Fixed& fp) const
{
	Fixed result;
    result.setRawBits(fp_Num_Val + fp.fp_Num_Val);
    return (result);
}

Fixed Fixed::operator-(const Fixed& fp) const
{
	Fixed result;
	result.setRawBits(fp_Num_Val - fp.fp_Num_Val);
	return (result);
}
/*NEEDED TO AVOID DOUBLE SCALING*/
Fixed Fixed::operator*(const Fixed& fp) const
{
	Fixed result;
	long long temp = (long long)fp_Num_Val * (long long)fp.fp_Num_Val;
	result.setRawBits(temp>>frac_Bits);
	return (result);
}

Fixed Fixed::operator/(const Fixed& fp) const
{
	Fixed result;
	long long temp = (long long)fp_Num_Val<<frac_Bits;
	result.setRawBits(temp/ fp.fp_Num_Val);
	return (result);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	fp_Num_Val++;
	return (temp);
}

Fixed& Fixed::operator++()
{
	++fp_Num_Val;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	fp_Num_Val--;
	return (temp);
}

Fixed& Fixed::operator--()
{
	--fp_Num_Val;
	return (*this);
}