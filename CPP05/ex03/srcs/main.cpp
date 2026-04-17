/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:41:06 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/18 00:08:06 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/Bureaucrat.hpp"


int main()
{
	// Bureaucrat John = Bureaucrat("John", 140);
	// Bureaucrat PRESIDENT = Bureaucrat("Zaphod", 5);
	// Bureaucrat Jill = Bureaucrat("Jill", 150);

	Intern	someRandomIntern;
	AForm*	rrf;

	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");

	// ShrubberyCreationForm fromy = ShrubberyCreationForm("out");
	// PresidentialPardonForm formy2 = PresidentialPardonForm("scoundrel");
	// formy2.beSigned(PRESIDENT);
	// PRESIDENT.executeForm(formy2);

	// RobotomyRequestForm robot = RobotomyRequestForm("robot");
	// RobotomyRequestForm robot1 = RobotomyRequestForm("robot1");

	// robot.beSigned(PRESIDENT);
	// PRESIDENT.executeForm(robot);

	// fromy.beSigned(John);
	// John.executeForm(fromy);
}