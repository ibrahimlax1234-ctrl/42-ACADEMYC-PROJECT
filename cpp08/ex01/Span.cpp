/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 06:05:23 by librahim          #+#    #+#             */
/*   Updated: 2025/11/28 22:49:49 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"


Span::Span(void)
{
    N = 0;
}

Span::~Span() {}


Span::Span(const Span &o)
{
    N = o.N;
    ar = o.ar;
}

Span &Span::operator=(const Span &o)
{
	if (this == &o)
	    return *this;   
	N = o.N;
	ar = o.ar;
	return *this;
}

Span::Span(unsigned int n)
{
    N = n;
}

void Span::addNumber(int n)
{
	if (ar.size() >= N)
		throw std::logic_error("maximum numbers reached");  
	ar.push_back(n);
}

int Span::longestSpan()
{
    int longest_dist;

    if (ar.size() >= 2)
    {
        std::vector<int>::iterator ptr_tomin = std::min_element(ar.begin(), ar.end());
        std::vector<int>::iterator ptr_tomax = std::max_element(ar.begin(), ar.end());
        longest_dist = *ptr_tomax - *ptr_tomin;
    }
    else
	    throw std::exception();
    return (longest_dist);
}

int Span::shortestSpan()
{
    unsigned int finalresult;
    unsigned int test_res;
    std::vector<int> tmp = ar;

    if (ar.size() >= 2)
    {
        std::sort(tmp.begin(), tmp.end());
        finalresult =tmp.at(1) - tmp.at(0);
        int i = 0;
        while (++i < (int)ar.size() - 1)
        {
            test_res = tmp.at(i + 1) - tmp.at(i);
            if ( test_res < finalresult)
                finalresult = test_res;
        }
    }
    else
	    throw std::exception();
    return finalresult;
}

void Span::addNumbers(std::vector<int>::iterator a, std::vector<int>::iterator b)
{
    unsigned int size_after = std::distance(a, b) + ar.size();

    if (size_after <= N)
        ar.insert(ar.end(), a, b);
    else
        throw std::exception();
}
