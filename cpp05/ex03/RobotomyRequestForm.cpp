/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:35:41 by librahim          #+#    #+#             */
/*   Updated: 2025/10/06 00:36:25 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"

// RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises, then informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, it informs that the robotomy failed.

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobForm", 72, 45) {
    target = "generic target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string tar) : AForm("RobForm", 72, 45)
{
    target = tar;
}

RobotomyRequestForm::~RobotomyRequestForm() {}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& o) : AForm("RobForm", 72, 45)
{
    target = o.target;
}


RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& o)
{
    target = o.target;
    return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
    return target;
}

void        RobotomyRequestForm::setTarget(std::string t)
{
    target = t;
}

void        RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->get_issign() == false)
        throw (AForm::FormNotSigned());
    if ((executor.getGrade() > this->get_g_toex()))
        throw (Bureaucrat::GradeTooLowException());
    std::cout << "* Drilling noise * ..."<<std::endl;
    int g = std::rand() % 2;
    if (g == 1)
        std::cout << "the target " << target << " is now robotomized successfully." << std::endl;
    else
        std::cout << "the target " << target << " failed to be robotomized. good luck next time" << std::endl;
}
