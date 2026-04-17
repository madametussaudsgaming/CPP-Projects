/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:41:06 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/17 14:54:15 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"


int main()
{
	Bureaucrat John = Bureaucrat("John", 140);
	Bureaucrat PRESIDENT = Bureaucrat("Zaphod", 5);
	Bureaucrat Jill = Bureaucrat("Jill", 150);

	ShrubberyCreationForm fromy = ShrubberyCreationForm("out");
	PresidentialPardonForm formy2 = PresidentialPardonForm("scoundrel");
	formy2.beSigned(PRESIDENT);
	PRESIDENT.executeForm(formy2);

	RobotomyRequestForm robot = RobotomyRequestForm("robot");
	RobotomyRequestForm robot1 = RobotomyRequestForm("robot1");

	robot.beSigned(PRESIDENT);
	PRESIDENT.executeForm(robot);

	// fromy.beSigned(John);
	// John.executeForm(fromy);
}