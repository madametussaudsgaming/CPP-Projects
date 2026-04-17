/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 22:16:18 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/17 15:01:47 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : public AForm {
	private:
		const std::string formTarget;
		RobotomyRequestForm(void);

	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &ori);
		using	AForm::operator=;
		~RobotomyRequestForm();

		void execute(const Bureaucrat &executor) const;
		const std::string& getTarget() const;
};