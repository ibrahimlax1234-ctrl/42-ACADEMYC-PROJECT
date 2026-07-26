/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 05:16:42 by librahim          #+#    #+#             */
/*   Updated: 2025/11/18 02:53:17 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}


ScalarConverter::ScalarConverter(const ScalarConverter  &o)
{
    (void)o;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& o)
{
	(void)o;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

int is_onechar(std::string input)
{
    if (input.size() == 1)  
    {
        unsigned char t = static_cast<unsigned char>(input.at(0));
        if (!std::isdigit(t))
            return 1;
    }
    return 0;
}

int handle_pseudolit(std::string input)
{
    if (input == "inf" || input == "inff")
        throw std::exception();
    if (!(input == "nan" || input == "nanf" || input == "+inff" ||  input == "-inff" || input == "+inf" || input == "-inf"))
        return 0;
    if (input == "nan" || input == "nanf")
    {
        std::cout << "Char: Impossible" <<std::endl;
        std::cout << "Int: Impossible" << std::endl;
        std::cout << "Float: nanf" << std::endl;
        std::cout << "Double: nan" << std::endl;
    }
    else if (input == "+inf" || input == "+inff")
    {
        std::cout << "Char: Impossible" <<std::endl;
        std::cout << "Int: Impossible" << std::endl;
        std::cout << "Float: +inff" << std::endl;
        std::cout << "Double: +inf" << std::endl;
    }
    else if (input == "-inf" || input == "-inff")
    {
        std::cout << "Char: Impossible" <<std::endl;
        std::cout << "Int: Impossible" << std::endl;
        std::cout << "Float: -inff" << std::endl;
        std::cout << "Double: -inf" << std::endl;
    }
    return 1;
}

void handle_onechar(std::string input)
{
        char c = static_cast<char>(input.at(0));
        int i = static_cast<int>(c);
        float f = static_cast<float>(c);
        double d = static_cast<double>(c);
        if ((c >= 0 && c <= 127) && std::isprint(static_cast<unsigned char>(c)))
            std::cout << "Char: '" << c <<"'"<< std::endl;
        else
            std::cout << "Char: non displayable"<< std::endl;
        std::cout << "Int: " << i << std::endl;
        std::cout << "Float: "  << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
        return;
}


void check(const std::string& inp)
{
    char* end;
    double val = strtod(inp.c_str(), &end);
    (void)val;
    if (*end == '\0') 
            return;
    if (*end == 'f' && *(end + 1) == '\0') 
            return;
    throw std::exception();   
}



void ScalarConverter::convert(std::string input)
{
    double  v;

    try
    {
        if (is_onechar(input))
            return handle_onechar(input);
        if (handle_pseudolit(input))
            return;
        check(input);
        char* end;
        if (input[input.size() - 1] == 'f')
            v = strtof(input.c_str(), &end);
        else
            v = strtod(input.c_str(), &end);

        if ((v >= 0 && v <= 127) && std::isprint(static_cast<unsigned char>(v)))
            std::cout << "char: " << static_cast<char>(v) << std::endl;
        else
            std::cout << "char: non displayable" << std::endl;

        std::cout << "int: " << static_cast<int>(v) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(v) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << v << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible"<< std::endl;
        std::cout << "double: impossible"<<std::endl;
    }
}
