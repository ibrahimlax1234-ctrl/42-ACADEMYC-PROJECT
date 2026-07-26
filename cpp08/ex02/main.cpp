/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 23:40:53 by librahim          #+#    #+#             */
/*   Updated: 2025/11/28 23:45:38 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

int main()
{
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        mstack.push(80);
        mstack.push(740);
        mstack.push(0);
        mstack.push(-842);
		
        std::cout<<"last elem:" << mstack.top() << std::endl;
        std::cout <<"current size:" << mstack.size() << std::endl;
        mstack.pop();
        std::cout<<"last elem:"  << mstack.top() << std::endl;
        std::cout <<"current size:"<< mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        std::cout <<"current size:"<< mstack.size() << std::endl;
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
            std::cout<<"value of it:" << *it << std::endl;
        ++it;
            std::cout <<"value of it:"<< *it << std::endl;
        --it;
            std::cout<<"value of it:" << *it << std::endl;
        while (it != ite)
        {
            std::cout <<"value of it:" << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
        return 0;
}

// int main()
// {
//     std::list<int> mstack;

//     mstack.push_back(5);
//     mstack.push_back(17);

//     std::cout << mstack.back() << std::endl;

//     mstack.pop_back();

//     std::cout << mstack.size() << std::endl;

//     mstack.push_back(3);
//     mstack.push_back(5);
//     mstack.push_back(737);
//     mstack.push_back(0);
//     std::list<int>::iterator it = mstack.begin();
//     std::list<int>::iterator ite = mstack.end();

//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
// 	return 0;
// }