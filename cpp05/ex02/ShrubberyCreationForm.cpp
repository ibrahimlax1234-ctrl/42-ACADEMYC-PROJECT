/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:35:31 by librahim          #+#    #+#             */
/*   Updated: 2025/10/06 00:37:52 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SHRUBForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string tar) : AForm("SHRUBForm", 145, 137)
{
    target = tar;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& o) : AForm("SHRUBForm", 145, 137)
{
    target = o.target;
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& o)
{
    target = o.target;
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}

void        ShrubberyCreationForm::setTarget(std::string t)
{
    target = t;
}

void        ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->get_issign() == false)
        throw AForm::FormNotSigned();
    if ((executor.getGrade() > this->get_g_toex()))
        throw (Bureaucrat::GradeTooLowException());
    std::string n_f = this->target;
    n_f.append("_shruberry");
    std::ofstream f(n_f);
    if (!f)
        return ;
    for (int i = 0; i <= 3; i++)
    {
        f << "           ^\n          ^^^\n         ^^^^^\n           |\n"<<std::endl;
        f << "   ^\n  ^^^\n ^^^^^\n   |\n"<<std::endl;
        f << "        ^\n       ^^^\n      ^^^^^\n        |\n"<<std::endl;
        f << "      ^\n     ^^^\n    ^^^^^\n      |\n"<<std::endl;
    }
    f.close();
}
