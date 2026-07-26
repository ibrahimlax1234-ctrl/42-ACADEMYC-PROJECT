/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:24:45 by librahim          #+#    #+#             */
/*   Updated: 2025/11/15 20:56:06 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{
    Base *ret = NULL;
    int x;
    x = std::rand() % 3;
    if (x == 0)
       ret = new A();
    else if (x == 1)
       ret = new B();
    else if (x == 2)
       ret = new C();
    return ret;
}

void identify(Base* p)
{
    if (p == dynamic_cast<A*>(p))
        std::cout << "the type is A" << std::endl;
    else if (p == dynamic_cast<B*>(p))
        std::cout << "the type is B" << std::endl;
    else if (p == dynamic_cast<C*>(p))
        std::cout << "the type is C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        Base& r = dynamic_cast<A&>(p);
        std::cout << "the type is A" << std::endl;
        (void)r;
        return;
    }
    catch (std::exception &e)
    {}

    try
    {
        Base& r = dynamic_cast<B&>(p);
        std::cout << "the type is B" << std::endl;
        (void)r;
        return;
    }
    catch (std::exception &e)
    {}

    try
    {
        Base& r = dynamic_cast<C&>(p);
        std::cout << "the type is C" << std::endl;
        (void)r;
        return;
    }
    catch (std::exception &e)
    {}
}