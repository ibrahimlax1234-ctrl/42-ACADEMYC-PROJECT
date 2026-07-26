/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 23:28:07 by librahim          #+#    #+#             */
/*   Updated: 2025/11/29 00:26:55 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <deque>


template <typename T> class MutantStack : public std::stack<T>
{
    public:

        MutantStack() : std::stack<T>() {}
        ~MutantStack(){}
        MutantStack(MutantStack const& o) : std::stack<T>(o) {}
        MutantStack &operator=(MutantStack const& o)
        {
            std::stack<T>::operator=(o);
            return *this;
        }
        
        typedef typename std::deque<T>::iterator iterator;      

        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
};


#endif







// path of source code
// /Library/Developer/CommandLineTools/usr/include/c++/v1/stack
// /Library/Developer/CommandLineTools/usr/include/c++/v1/vector
// /Library/Developer/CommandLineTools/usr/include/c++/v1/deque
