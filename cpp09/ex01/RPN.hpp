/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:21:46 by librahim          #+#    #+#             */
/*   Updated: 2025/12/02 04:02:48 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <cctype>
#include <exception>

class RPN
{
    public:
        RPN();
        RPN(RPN const& o);
        RPN&    operator=(RPN const& o);
        ~RPN();
        static void run(std::string math_exp);
};

#endif