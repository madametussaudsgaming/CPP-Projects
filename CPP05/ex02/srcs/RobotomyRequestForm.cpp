/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:44:02 by rpadasia          #+#    #+#             */
/*   Updated: 2026/05/18 14:18:13 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", 72, 45), formTarget("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), formTarget(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ori)
	: AForm("RobotomyRequestForm", 72, 45), formTarget(ori.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string& RobotomyRequestForm::getTarget() const
{
	return(this->formTarget);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->canExecute(executor);
	std::srand(std::time(0));
	if (rand() % 2)
    	std::cout <<"IM DRILLING IT!"<<std::endl<< this->getTarget() << " has been robotized!" << std::endl;
	else
    	std::cout << this->getTarget() << " failed to robotize!" << std::endl;

}