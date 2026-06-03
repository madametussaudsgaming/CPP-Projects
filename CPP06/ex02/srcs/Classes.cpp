/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:26:10 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/28 19:27:47 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Classes.hpp"

Base::~Base() {}

Base* generate(void)
{
	Base *base;
	switch (std::rand() % 3)
	{
		case 0:  base = new A(); break;
		case 1:  base = new B(); break;
		default: base = new C(); break;
	}
	return base;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try { (void)dynamic_cast<A&>(p); std::cout << "A" << std::endl; return; }
	catch (const std::exception &e) {}
	try { (void)dynamic_cast<B&>(p); std::cout << "B" << std::endl; return; }
	catch (const std::exception &e) {}
	try { (void)dynamic_cast<C&>(p); std::cout << "C" << std::endl; return; }
	catch (const std::exception &e) {}
}
