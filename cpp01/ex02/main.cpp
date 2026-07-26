/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:55:33 by librahim          #+#    #+#             */
/*   Updated: 2025/05/13 04:50:08 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string s;
    s = "HI THIS BRAIN";

    std::string *stringPTR;
    stringPTR = &s;

    std::string &stringREF = s;


    std::cout << "adress of string s : "<< &s << std::endl;
    std::cout << "content of the pointer stringPTR : " << stringPTR << std::endl;
    std::cout << "adress of the reference stringREF: " << &stringREF  << std::endl;

    std::cout << std::endl;

    std::cout << "value of s = "<<s << std::endl;
    std::cout << "value of dereferencing the stringPTR = "<< *stringPTR << std::endl;
    std::cout << "value of stringREF = "<< stringREF << std::endl;

    return 0;
}
