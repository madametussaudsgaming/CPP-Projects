/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:14:59 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/28 16:20:02 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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