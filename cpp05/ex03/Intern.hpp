/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:33:10 by librahim          #+#    #+#             */
/*   Updated: 2025/08/20 18:09:24 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern
{
    public :
        Intern();
        ~Intern();
        Intern(Intern const & o);
        Intern& operator=(Intern const & o);

        AForm* makeForm(std::string form_name, std::string target);
		class FormNotExisting : public std::exception
		{
			const char* what() const throw();
		};
};

#endif