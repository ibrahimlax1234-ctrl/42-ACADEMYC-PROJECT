/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 06:03:21 by librahim          #+#    #+#             */
/*   Updated: 2025/11/28 22:50:10 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>    
#include <iterator>     

class Span
{
    private:
        std::vector<int> ar;
        unsigned int     N;

    public:
        
                Span();
                ~Span();
                Span(Span const &o);
        Span    &operator=(Span const &o);
    
                Span(unsigned int n);
        void    addNumber(int n);
        int     longestSpan();
        int     shortestSpan();
        void    addNumbers(std::vector<int>::iterator a, std::vector<int>::iterator b);
};

#endif