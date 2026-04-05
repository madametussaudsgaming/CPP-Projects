/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 22:16:23 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/05 17:34:36 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		const std::string formTarget;
		ShrubberyCreationForm(void);

	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &ori);
		using	AForm::operator=;
		~ShrubberyCreationForm();

		void execute(const Bureaucrat &executor) const;
		const std::string& getTarget() const;
};