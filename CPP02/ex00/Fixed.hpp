/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:14:59 by rpadasia          #+#    #+#             */
/*   Updated: 2026/03/08 16:23:51 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_FIXED_HPP
#define EX00_FIXED_HPP

#include <iomanip>
#include <iostream>

class Fixed
{
	private:
	int					fp_Num_Val;
	static const int	frac_Bits = 8;

	public:
	Fixed();
	Fixed(Fixed& variables);
	~Fixed();
	Fixed& operator=(const Fixed& variables);

	int	getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif