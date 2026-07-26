/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:23:10 by librahim          #+#    #+#             */
/*   Updated: 2025/12/10 06:58:31 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int c, char *v[])
{
    if (c != 2)
    {
        std::cerr << "Error: usage : ./RPN \"expression\"" << std::endl;
        return 1;
    }
    try
    {
        std::string exp = v[1];
        RPN::run(exp);
    }
    catch (std::exception &e)
    {}
    return 0;
}