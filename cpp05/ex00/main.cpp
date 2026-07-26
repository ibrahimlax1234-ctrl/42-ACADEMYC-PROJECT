/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 01:49:09 by librahim          #+#    #+#             */
/*   Updated: 2025/10/06 16:34:43 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

int main()
{
   try
   {
      Bureaucrat   s("NPC", -1);
   }
   catch (std::exception &e)
   {
      std::cerr<< "caught an exception : " << e.what() <<std::endl;
   }
   
   try
   {
      Bureaucrat   s("NPC", 151);
   }
   catch (std::exception &e)
   {
      std::cerr << "caught an exception : " << e.what() <<std::endl;
   }

   try
   {
      Bureaucrat   s("NPC", 1);
      s.increm_grade();
   }
   catch (std::exception &e)
   {
      std::cerr<< "caught an exception : " << e.what() <<std::endl;
   }
 

   try
   {
      Bureaucrat   s("NPC", 150);
      s.decrem_grade();
   }
   catch (std::exception &e)
   {
      std::cerr << "caught an exception : " << e.what() <<std::endl;
   }

   try
   {
      Bureaucrat test("NPC", 100);
      std::cout << test <<std::endl;
      Bureaucrat test2(test);
      std::cout << test2 <<std::endl;
      
   }
   catch(const std::exception& e)
   {
      std::cerr << "caught an exception : " << e.what() << std::endl;
   }

   return 0;
}
