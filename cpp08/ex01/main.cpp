/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:26:16 by librahim          #+#    #+#             */
/*   Updated: 2025/11/28 21:33:55 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <vector>


// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return 0;
// }

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(10);
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error1 : only 1 number in the array"<< std::endl;
    }

    try
    {
        Span s = Span(2);
        s.addNumber(12);
        s.addNumber(35);
        s.addNumber(989);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error2 : limit to add is exceeded"<< std::endl;
    }

    std::srand(std::time(NULL));
    try
    {
        std::vector<int> bigVec;
        int k;
        for (int i = 0; i < 20000; i++)
        {
            k = i + (std::rand() % 2147443647);
            bigVec.push_back(k);
        }

        Span spBig(20000);
        spBig.addNumbers(bigVec.begin(), bigVec.end());
        std::cout << "Shortest: " << spBig.shortestSpan() << std::endl;
        std::cout << "Longest:  " << spBig.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error3" << std::endl;
    }

    return 0;
}