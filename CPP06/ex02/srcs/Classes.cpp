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
	std::srand(time(NULL));
	//rely on implicit conversion
	Base *base;
	switch (std::rand() % 3)
	{
		case 0:
			std::cout<<"A"<<std::endl;
			base = new A();
			break;
		case 1:
			std::cout<<"B"<<std::endl;
			base = new B();
			break;
		case 2:
			std::cout<<"C"<<std::endl;
			base = new C();
			break;
		default:
    		std::cout<<"ERROR"<<std::endl;
    		exit(1);
	}
	return base;
}

void identify(Base* p)
{
	if (dynamic_cast <A*> (p))
		std::cout<<"Is A"<<std::endl;
	else if (dynamic_cast <B*> (p))
		std::cout<<"Is B"<<std::endl;
	else if (dynamic_cast <C*> (p))
		std::cout<<"Is C"<<std::endl;
	else
		std::cout<<"Not a derived class"<<std::endl;
}

//can't have a reference to nullptr, need to use try catch lol
void identify(Base& p)
{
    try { (void)dynamic_cast<A&>(p); std::cout <<"Is A"<< std::endl; return; }
    catch (const std::exception &e) {}
    try { (void)dynamic_cast<B&>(p); std::cout <<"Is B"<< std::endl; return; }
    catch (const std::exception &e) {}
    try { (void)dynamic_cast<C&>(p); std::cout <<"Is C"<< std::endl; return; }
    catch (const std::exception &e) {}
	std::cout<<"Not a derived class"<<std::endl;
}
