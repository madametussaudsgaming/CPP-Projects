/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:15:57 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/28 19:20:45 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <iomanip>
#include <stdint.h>
#include <ctime>

class Base {
	public:
		virtual ~Base() = 0;
};

class A : public Base {

};

class B : public Base {

};

class C : public Base {

};

void identify(Base* p);
void identify(Base& p);
Base* generate(void);