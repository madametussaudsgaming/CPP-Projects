/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 16:58:00 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/05 17:37:39 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), formTarget("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), formTarget(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ori)
	: AForm("ShrubberyCreationForm", 145, 137), formTarget(ori.getTarget()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return(this->formTarget);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	file;
	std::string		name;

	this->canExecute(executor);
	name = formTarget + "_shrubbery";
	file.open(name.c_str(), std::ofstream::out);

	file<<"( )"<<std::endl;
	file<<"( )"<<std::endl;
	file<<"( )"<<std::endl;
	file<<" | "<<std::endl;
	file.close();
}