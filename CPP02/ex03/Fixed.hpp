/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:14:59 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/30 16:01:07 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

class Fixed
{
	private:
	int					fp_Num_Val;
	static const int	frac_Bits = 8;

	public:
	Fixed();
	Fixed(const Fixed& variables);
	Fixed(const int param);
	Fixed(const float param);
	~Fixed();


	/*overloading*/
	Fixed& operator=(const Fixed& variables);

	int operator==(const Fixed& fp) const;
	int operator>=(const Fixed& fp) const;
	int operator<=(const Fixed& fp) const;
	int operator>(const Fixed& fp) const;
	int operator<(const Fixed& fp) const;
	int operator!=(const Fixed& fp) const;

	Fixed operator+(const Fixed& fp) const;
	Fixed operator-(const Fixed& fp) const;
	Fixed operator*(const Fixed& fp) const;
	Fixed operator/(const Fixed& fp) const;

	Fixed operator++(int);
	Fixed& operator++();
	Fixed operator--(int);
	Fixed& operator--();

	int		getRawBits( void ) const;
	float	toFloat( void ) const;
	int		toInt( void ) const;
	void	setRawBits( int const raw );

	static Fixed& min(Fixed& fp1, Fixed& fp2);
	static const Fixed& min(const Fixed& fp1, const Fixed& fp2);
	static Fixed& max(Fixed& fp1, Fixed& fp2);
	static const Fixed& max(const Fixed& fp1, const Fixed& fp2);
};

std::ostream& operator<<(std::ostream &out, const Fixed& fp_Num);
