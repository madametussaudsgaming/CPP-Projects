/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 22:16:16 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/17 14:32:00 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		const std::string formTarget;
		PresidentialPardonForm(void);

	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &ori);
		using	AForm::operator=;
		~PresidentialPardonForm();

		void execute(const Bureaucrat &executor) const;
		const std::string& getTarget() const;
};