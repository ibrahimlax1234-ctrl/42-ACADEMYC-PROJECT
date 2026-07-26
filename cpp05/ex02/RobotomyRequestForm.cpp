/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:35:41 by librahim          #+#    #+#             */
/*   Updated: 2025/10/06 00:38:08 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"

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
        throw AForm::FormNotSigned();
    if ((executor.getGrade() > this->get_g_toex()))
        throw (Bureaucrat::GradeTooLowException());
    std::cout << "* Drilling noise * ..."<<std::endl;
    sleep(1);
    unsigned long t = std::time(NULL);
    if (t % 2 == 0)
       std::cout << this->target << " has been successfully robotomized" << std::endl;
    else
        std::cout << this->target << " has failed to be robotomized" << std::endl;
}
