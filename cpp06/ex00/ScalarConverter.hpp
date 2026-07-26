/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:34:15 by librahim          #+#    #+#             */
/*   Updated: 2025/11/15 20:58:13 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib> // fiha atoi, atof, strtol, strtod
#include <cctype>  // fiha isprint


class ScalarConverter
{
    private:
                    ScalarConverter();
                    ScalarConverter(const ScalarConverter &o);
                    ScalarConverter &operator=(const ScalarConverter &o);
                    ~ScalarConverter();
    public:
        static void convert(std::string input);
};

#endif