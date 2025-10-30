/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:14:59 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/28 20:51:28 by rpadasia         ###   ########.fr       */
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


	int		getRawBits( void ) const;
	float	toFloat( void ) const;
	int		toInt( void ) const;
	void	setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream &out, const Fixed& fp_Num);
