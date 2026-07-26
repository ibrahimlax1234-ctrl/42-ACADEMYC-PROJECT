/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:35:29 by librahim          #+#    #+#             */
/*   Updated: 2025/10/07 21:40:44 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Intern.hpp"
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// void l(){system("leaks ex03");}
int main()
{
    // atexit(l);
    try
    {
        Intern someIntern;
        Bureaucrat b("advisor", 1);

        AForm* form1 = someIntern.makeForm("shrubbery creation", "Garden");
        AForm* form2 = someIntern.makeForm("robotomy request", "Bender");
        AForm* form3 = someIntern.makeForm("presidential pardon", "Alice");
        AForm* form4 = someIntern.makeForm("unknown form", "Nobody");
        
        b.signForm(*form1);
        b.signForm(*form2);
        b.signForm(*form3);
        b.signForm(*form4);

        b.executeForm(*form1);
        b.executeForm(*form2);
        b.executeForm(*form3);
        b.executeForm(*form4);

        delete form1;
        delete form2;
        delete form3;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
    