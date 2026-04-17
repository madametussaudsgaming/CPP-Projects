/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 22:36:33 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/17 23:19:14 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern &ori) { *this = ori; }

Intern& Intern::operator=(const Intern& ori) {
	(void)ori;
	return (*this);}

Intern::~Intern(void) {}

AForm *Intern::makeForm(std::string formName, std::string target) {

	t_form options[] = {
		{"PresidentialPardonForm", new PresidentialPardonForm(target)},
		{"RobotomyRequestForm", new RobotomyRequestForm(target)},
		{"ShrubberyCreationForm", new ShrubberyCreationForm(target)},
		{"", NULL }
	};
	AForm *formFinal;
	formFinal = NULL;
	for (int i = 0; options[i].form != NULL; i++)
	{
		if (formName == options[i].type)
		{
			formFinal = options[i].form;
		}
		else
			delete options[i].form;
	}
	if (formFinal == NULL)
		std::cout << "Form " << formName << " not found"<< std::endl;
	else
		std::cout<<"Intern creates "<< formName<< std::endl;
	return formFinal;
}