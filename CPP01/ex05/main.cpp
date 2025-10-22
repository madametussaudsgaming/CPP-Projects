/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:47:37 by rpadasia          #+#    #+#             */
/*   Updated: 2025/10/12 22:01:22 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl error1;
	error1.complain("DEBUG");
	std::cout<<std::endl;
	Harl error2;
	error2.complain("INFO");
	std::cout<<std::endl;
	Harl error3;
	error3.complain("WARNING");
	std::cout<<std::endl;
	Harl error4;
	error4.complain("ERROR");
	std::cout<<std::endl;
	Harl error5;
	error5.complain("WUMBO");
	std::cout<<std::endl;
}