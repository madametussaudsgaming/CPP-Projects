/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:41:06 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/02 22:00:49 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
	Bureaucrat John = Bureaucrat("John", 150);
	try {
		John.decrementGrade();
	}
	catch (std::exception &e0) {
		std::cout<<e0.what()<<std::endl;
	}

	try {
		Bureaucrat Jake = Bureaucrat("Jake", 160);
	}
	catch (std::exception &e1) {
		std::cout<<e1.what()<<std::endl;
	}

}