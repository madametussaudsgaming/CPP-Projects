/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:41:06 by rpadasia          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/05/16 18:39:17 by rpadasia         ###   ########.fr       */
=======
/*   Updated: 2026/05/14 18:40:55 by rpadasia         ###   ########.fr       */
>>>>>>> 801733e8081a1db29408091569429af6c2546a4a
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
