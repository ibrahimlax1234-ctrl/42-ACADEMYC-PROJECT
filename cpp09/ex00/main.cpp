/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 03:32:58 by librahim          #+#    #+#             */
/*   Updated: 2025/12/09 18:04:51 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int c, char *v[])
{
    if (c == 1)
    {
        std::cerr << "Error: could not open file" <<std::endl;
        return 1;
    }
    if (c !=2)
    {
        std::cerr << "usage : ./btc <filename.txt>"<<std::endl;
        return 1;
    }
    try
    {
        std::string inp = v[1];
        if (inp.size() == 0)
        {
            std::cerr << "Error: could not open file" <<std::endl;
            throw std::exception();
        }
        BitcoinExchange a(inp);
        a.run();
    }
    catch(const std::exception& e) {}

    return 1;
}
