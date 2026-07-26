/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:28:48 by librahim          #+#    #+#             */
/*   Updated: 2025/11/23 16:26:06 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>
#include <exception>

// void f()
// {
//     system("leaks ex02");
// }
int main()
{
    // atexit(f);
    Array<int> *a = new Array<int>(5);
    try
    {
        std::cout << "SIZE IS " <<a->size() << " and members are :" << std::endl;
        std::cout <<(*a)[0]<< std::endl;
        std::cout <<(*a)[1]<< std::endl;
        std::cout <<(*a)[2]<< std::endl;
        std::cout <<(*a)[3]<< std::endl;
        std::cout <<(*a)[4]<< std::endl;
        (*a)[0] = 654;
        (*a)[1] = 123;
        (*a)[2] = 987;
        (*a)[3] = 159;
        (*a)[4] = 75;
        std::cout << "after modifying members " <<std::endl;
        std::cout <<(*a)[0]<< std::endl;
        std::cout <<(*a)[1]<< std::endl;
        std::cout <<(*a)[2]<< std::endl;
        std::cout <<(*a)[3]<< std::endl;
        std::cout <<(*a)[4]<< std::endl;
        std::cout << "attemting to access by an index outof bound :" << std::endl;
        (*a)[20] = 75;
    }
    catch(std::exception& e)
    {
        std::cerr << "Cautt excpetion :access out of bound "<<std::endl;
    }
    delete a;

    std::cout << "-----------------------------------------------------------------------------------------------------------"<<std::endl<<std::endl;

    Array<std::string> *b = new Array<std::string>(5);
    try
    {
        std::cout << "SIZE IS " <<b->size() << " and members are :" << std::endl;
        std::cout << ">>" <<(*b)[0]<< std::endl;
        std::cout << ">>" << (*b)[1]<< std::endl;
        std::cout << ">>"<< (*b)[2]<< std::endl;
        std::cout <<">>" <<(*b)[3]<< std::endl;
        std::cout << ">>"<< (*b)[4]<< std::endl;
        (*b)[0] = "first string";
        (*b)[1] = "secnd string";
        (*b)[2] = "3rd string";
        (*b)[3] = "4th string";
        (*b)[4] = "5th string";
        std::cout << "after modifying members " <<std::endl;
        std::cout <<(*b)[0]<< std::endl;
        std::cout <<(*b)[1]<< std::endl;
        std::cout <<(*b)[2]<< std::endl;
        std::cout <<(*b)[3]<< std::endl;
        std::cout <<(*b)[4]<< std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << "Cautt excpetion: access out of bound"<<std::endl;
    }
    delete b;
    return 0;
}
