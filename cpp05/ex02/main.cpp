/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:35:29 by librahim          #+#    #+#             */
/*   Updated: 2025/10/07 21:38:38 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat s("form_slayer", 120);

        ShrubberyCreationForm   tree_form("trees");
        s.signForm(tree_form);

        s.executeForm(tree_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << "caight exception :"<< e.what() << std::endl;
    }

    std::cout << " ========================================================================"<<std::endl;
    try
    {
        Bureaucrat s("form_slayer", 150);
        RobotomyRequestForm   f("home");
        s.executeForm(f);
        s.executeForm(f);
    }
    catch(const std::exception& e)
    {
        std::cerr << "caight exception :"<< e.what() << std::endl;
    }
    std::cout << " ========================================================================"<<std::endl;
    try
    {
        Bureaucrat s("form_slayer", 1);
        PresidentialPardonForm   f("presi_target");
        s.executeForm(f);
    }
    catch(const std::exception& e)
    {
        std::cerr << "caight exception :"<< e.what() << std::endl;
    }
    
    std::cout << " ========================================================================"<<std::endl;
    try
    {
        
        Bureaucrat s("form_slayer", 150);
        PresidentialPardonForm   f("presi_target");
        s.signForm(f);
        s.executeForm(f);
    }
    catch(const std::exception& e)
    {
        std::cerr << "caight exception :"<< e.what() << std::endl;
    }
    std::cout << " ========================================================================"<<std::endl;



    try
    {
        Bureaucrat d("form_slayer", 150);
        Bureaucrat s("form_signer", 1);
        ShrubberyCreationForm   tree_form("trees");
        s.signForm(tree_form);
        d.executeForm(tree_form);
        std::cout << tree_form;
    }
    catch(const std::exception& e)
    {
        std::cerr << "caight exception :"<< e.what() << std::endl;
    }

    std::cout << " ========================================================================"<<std::endl;


    try
    {
        Bureaucrat s("form_slayer", 1);
        PresidentialPardonForm   pres_form("someone");
        s.signForm(pres_form);
        s.executeForm(pres_form);
        std::cout << pres_form;
    }
    catch(const std::exception& e)
    {
        std::cerr << "caight exception :"<< e.what() << std::endl;
    }
    std::cout << " ========================================================================"<<std::endl;

    try
    {
        Bureaucrat s("form_slayer", 1);
        RobotomyRequestForm   rob("home");
        s.signForm(rob);
        s.executeForm(rob);
        std::cout << rob;
    }
    catch(const std::exception& e)
    {
        std::cerr << "caught exception :"<< e.what() << std::endl;
    }
    return 1;
}