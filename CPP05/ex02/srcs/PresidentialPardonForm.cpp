/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:32:30 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/17 14:39:03 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PresidentialPardonForm", 25, 5), formTarget("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), formTarget(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ori)
	: AForm("PresidentialPardonForm", 25, 5), formTarget(ori.getTarget()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string& PresidentialPardonForm::getTarget() const
{
	return(this->formTarget);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	this->canExecute(executor);
	std::cout<<this->getTarget()<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
}