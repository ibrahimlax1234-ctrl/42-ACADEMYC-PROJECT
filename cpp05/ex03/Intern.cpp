/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:33:17 by librahim          #+#    #+#             */
/*   Updated: 2025/10/06 20:50:49 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern(){}
Intern::~Intern(){}
Intern::Intern(Intern const & o){ (void)o;}
Intern&  Intern::operator=(Intern const & o)
{(void)o;
return *this;}  


AForm*  crShrub(std::string target)
{
    AForm *r = new ShrubberyCreationForm(target);
    return r ;
}
AForm*  crRob(std::string target)
{
    AForm *r = new RobotomyRequestForm(target);
    return r ;
}

AForm*  crPard(std::string target)
{
    AForm *r = new PresidentialPardonForm(target);
    return r ;
}

AForm*  Intern::makeForm(std::string form_name, std::string target)
{
    if (form_name.size() == 0)
    {
        std::cerr << "form name provided is empty" << std::endl;
        return 0;
    }
    std::string names[3] = { "shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*creators[3])(std::string) = {&crShrub, &crRob, &crPard};
    AForm *ret = 0;
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        if (form_name == names[i])
        {
            ret = creators[i](target);
            std::cout << "Intern creates " << form_name << std::endl;
            return ret;
        }
    }
    if (i == 3)
        std::cerr << "ERROR : intern cant detect this type of form because doesnt exit" << std::endl;
    return ret;
}
