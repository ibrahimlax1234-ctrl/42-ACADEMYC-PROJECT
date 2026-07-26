/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:22:11 by librahim          #+#    #+#             */
/*   Updated: 2025/12/10 07:31:03 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

RPN::RPN()
{}


RPN::RPN(RPN const& o)
{
        (void)o;
}

RPN&    RPN::operator=(RPN const& o)
{
        (void)o;
        return *this;
}

RPN::~RPN()
{}

int character_filter(std::string math_exp)
{
	size_t i = 0;
	while (i < math_exp.size())
	{
		if (!(std::isdigit(static_cast<unsigned char>(math_exp[i])) ||
			math_exp[i] == '+' || math_exp[i] == '-' || math_exp[i] == '/' ||
			math_exp[i] == '*' || math_exp[i] == ' '))
			return 1;
		i++;
	}
	return 0;
}

void    RPN::run(std::string math_exp)
{
    if (math_exp.size() == 0)
    {
		std::cerr << "Error : empty input"<<std::endl; 
		throw std::exception();
	}
	std::stack<int> nbrs;
	if (character_filter(math_exp))
	{
		std::cerr <<"Error : invalid character" <<std::endl;
		throw std::exception();
	}
	size_t i = 0;
	while (i < math_exp.size())
	{
		if (math_exp[i] == ' ')
		{
			i++;
			continue ;
		}
		else if (std::isdigit(static_cast<unsigned char>(math_exp[i])))
		{
			if (i+1 < math_exp.size() && std::isdigit(math_exp[i + 1]))
			{
				std::cerr << "Error : number is bigger than 9" << std::endl;
				throw std::exception();
			}

			if (i+1 < math_exp.size() && math_exp[i+1]!= ' ')
			{
				std::cerr << "Error : must be space separated" << std::endl;
				throw std::exception();
			}
			nbrs.push(math_exp[i] - '0');
			i++;
		}
		else
		{
			if (nbrs.size() < 2)
            {
                std::cerr << "Error : there is only 1 number to do operation " << std::endl;
				throw std::exception();
            }
            int b = nbrs.top();
            nbrs.pop();
            int a = nbrs.top();
            nbrs.pop();

			long long result = 0;
			if (math_exp[i] == '+')
				result = (long long)a + b;
			else if (math_exp[i] == '-')
				result =(long long) a - b;
			else if (math_exp[i] == '*')
				result = (long long) a * b;
			else if (math_exp[i] == '/' && b != 0)
				result = (long long) a / b;
			else if (math_exp[i] == '/' && b == 0)
			{
				std::cerr << "Error : division on 0" << std::endl;
				throw std::exception();
			}
			if ((result < -2147483648 || result > 2147483647))
			{
				std::cout << "error : Integer overflow : " << result<< std::endl;
				throw std::exception();
			}
			nbrs.push((static_cast<int>(result)));
			i++;
		}
	}
	if (nbrs.size() == 1)
		std::cout << nbrs.top() << std::endl;
	else
	{
		std::cerr << "Error : more than 1 at the end" << std::endl;
		throw std::exception();
	}
}
