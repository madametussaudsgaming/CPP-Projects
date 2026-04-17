/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 22:36:23 by rpadasia          #+#    #+#             */
/*   Updated: 2026/04/17 23:44:11 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	private:
		typedef struct	s_form
		{
			std::string	type;
			AForm		*form;
		}				t_form;
	public:
		Intern();
		Intern(Intern &ori);
		Intern& operator=(const Intern& ori);
		~Intern();

		AForm *makeForm(std::string formName, std::string target);
};