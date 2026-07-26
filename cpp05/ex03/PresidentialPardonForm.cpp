/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:35:45 by librahim          #+#    #+#             */
/*   Updated: 2025/10/06 00:36:05 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("SHRUBForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string tar) : AForm("SHRUBForm", 25, 5)
{
    target = tar;
}

PresidentialPardonForm::~PresidentialPardonForm() {}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& o) : AForm("SHRUBForm", 25, 5)
{
    target = o.target;
}


PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& o)
{
    target = o.target;
    return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
    return target;
}

void        PresidentialPardonForm::setTarget(std::string t)
{
    target = t;
}

void        PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->get_issign() == false)
        throw (AForm::FormNotSigned());
    if ((executor.getGrade() > this->get_g_toex()))
        throw (Bureaucrat::GradeTooLowException());
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" <<std::endl;
}