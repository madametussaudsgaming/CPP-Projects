/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:12:36 by rpadasia          #+#    #+#             */
/*   Updated: 2026/05/18 14:12:39 by rpadasia         ###   ########.fr       */
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
	//rmbr to make sure class not empty and operator overloaded correctly
	try {
		Bureaucrat Jake = Bureaucrat("Jake", 130);
		std::cout<<Jake<<std::endl;
	}
	catch (std::exception &e1) {
		std::cout<<e1.what()<<std::endl;
	}

}
