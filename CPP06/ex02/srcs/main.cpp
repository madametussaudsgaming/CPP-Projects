/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:56:33 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/28 19:28:05 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Classes.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(time(NULL)));
	Base *obj = generate();
	identify(obj);
	identify(*obj);
	delete obj;
}