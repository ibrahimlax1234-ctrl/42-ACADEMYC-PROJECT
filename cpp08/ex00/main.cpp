/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:26:35 by librahim          #+#    #+#             */
/*   Updated: 2025/11/27 05:57:19 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> ss;
    ss.push_back(0);
    ss.push_back(98);
    ss.push_back(46);
    ss.push_back(3);
    ss.push_back(345);
    ss.push_back(23);
    ss.push_back(12);
    try
    {
        easyfind(ss, 0);
        std::cout <<"the integer is found!"<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr <<"not found" << std::endl;
    }
    return 0;
}