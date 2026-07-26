/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 01:49:09 by librahim          #+#    #+#             */
/*   Updated: 2025/10/06 20:34:01 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
   try
   {
        Form f("fform", 151, 151);
   }
   catch(std::exception& e)
   {
    std::cerr <<"Caught exception :" << e.what() << std::endl;
   }
   

   std::cout << std::endl;
   try
   {
        Bureaucrat b("bob", 136);
        Form f("googleform", 135, 74);
        b.signForm(f);
   }
   catch(std::exception& e)
   {
        std::cerr <<"Caught exception :" << e.what() << std::endl;
   }
 std::cout << std::endl;
   try
   {
        Bureaucrat b("bob", 1);
        Form f("googleform", 135, 74);
        b.signForm(f);
        std::cout << f;
        std::cout << f.get_g_toex() << std::endl;
        std::cout << f.get_g_tosign() << std::endl;
        std::cout << f.get_issign() << std::endl;
        std::cout << f.getName() << std::endl;
   }
   catch(std::exception& e)
   {
        std::cerr << e.what() << std::endl;
   }

   return 1;
}
