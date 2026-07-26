/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:55:42 by librahim          #+#    #+#             */
/*   Updated: 2025/11/23 16:32:48 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"



// const fcts 
void c_printstr(std::string const&  elem)
{
    std::cout << elem << std::endl;;
}
void c_printint(int const& elem)
{
    std::cout << elem << std::endl;
}

void c_printfloat(float const& elem)
{
    std::cout << elem << std::endl;
}

// non const fcts
void printstr(std::string&  elem)
{
    std::cout << elem << std::endl;;
}
void printint(int& elem)
{
    std::cout << elem << std::endl;
}

void printfloat(float& elem)
{
    std::cout << elem << std::endl;
}


int main()
{
    std::string     str_ar[] = {"HELLO", "HOW", "ARE", "YOU"};
    int             int_ar[]={1, 50, 844, 4212512};
    float           fl_ar[] = {1.0f, 0.01f, 50.147f, 48888.5f};


    std::cout << "--------------------------------------------------------"<<std::endl;
    std::cout << ">>>>>>>>>iterating string aray"<<std::endl;
    iter<std::string>(str_ar, 4, &c_printstr);



    std::cout << "--------------------------------------------------------"<<std::endl;
    std::cout << ">>>>>>>>>iterating int aray"<<std::endl;
    iter<int>(int_ar, 4, &c_printint);

    
    
    std::cout << "--------------------------------------------------------"<<std::endl;
    std::cout << ">>>>>>>>>iterating float aray"<<std::endl;
    iter<float>(fl_ar, 4, &c_printfloat);
    std::cout << "--------------------------------------------------------"<<std::endl;

    
    return 0;    
}

