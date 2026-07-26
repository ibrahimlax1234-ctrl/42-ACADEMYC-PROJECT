/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:35:43 by librahim          #+#    #+#             */
/*   Updated: 2025/10/06 00:36:00 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"


class PresidentialPardonForm : public AForm
{
    private : 
        std::string target;
    public :
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(std::string tar);
        PresidentialPardonForm(PresidentialPardonForm& o);
        PresidentialPardonForm& operator=(PresidentialPardonForm& o);
        std::string getTarget() const;
        virtual void execute(Bureaucrat const & executor) const;
        void        setTarget(std::string t);
};

#endif