/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:14:57 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/29 18:31:34 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}

/*## Complete Decision Tree
```
Does the operator modify the original object?
│
├─ YES → Does it return the modified object itself?
│        │
│        ├─ YES → Return reference (Fixed&)
│        │        Examples: =, +=, -=, *=, /=, ++a, --a
│        │
│        └─ NO → Return copy (Fixed)
│                 Example: a++ (returns old value)
│
└─ NO → Return copy (Fixed)
         Examples: +, -, *, /, comparison operators
*/