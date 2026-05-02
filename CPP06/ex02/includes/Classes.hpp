/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:15:57 by rpadasia          #+#    #+#             */
/*   Updated: 2026/05/02 11:42:59 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
#define CLASSES_HPP

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

#endif