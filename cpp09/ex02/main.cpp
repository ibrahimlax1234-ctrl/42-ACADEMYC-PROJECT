/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 02:43:48 by librahim          #+#    #+#             */
/*   Updated: 2025/12/10 06:53:45 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int c, char **v)
{
    if (c == 1)
    {
        std::cerr << "Error : no input" <<std::endl;
        return 1;
    }
    try
    {
        PmergeMe::run(c,v);
    }
    catch(const std::exception& e) {}
    return 0;
}