/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:34:00 by librahim          #+#    #+#             */
/*   Updated: 2025/11/15 19:28:30 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

int main(int ac, char **v)
{
    if (ac != 2)
    {
        std::cerr << "bad input" <<std::endl;
        return 1;
    }
    std::string input = v[1];
    if (input.size() == 0)
    {
        std::cerr << "empty input" <<std::endl;
        return 1;
    }
    ScalarConverter::convert(input);
    return 0;
}