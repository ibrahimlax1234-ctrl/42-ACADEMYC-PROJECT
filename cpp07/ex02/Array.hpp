/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:10:58 by librahim          #+#    #+#             */
/*   Updated: 2025/11/23 16:39:21 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <string>
#include <exception>


template <typename T> class Array
{


    public :
        Array()
        {
            sz = 0;
            ar = NULL;
        }

        
        Array(unsigned int n)
        {
            sz = n;
            ar = new T[sz];
        }

        ~Array()
        {
            if (ar)
            {
                delete[] ar;
                ar = NULL;
            }
        }

        Array &operator=(Array const& otherr)
        {
            if (this != &otherr)
            {
                if (ar)
                    delete[] ar;
                sz = otherr.sz;
                if (sz)
                    ar= new T[sz];
                else
                    ar = NULL;
                int o=0;
                if (sz)
                {
                    while (o < (int) sz)
                    {
                        ar[o] = otherr.ar[o];
                        o++;
                    }
                }
            }
            return (*this);
        }
    

        Array(Array const& otherr)
        {

                sz = otherr.sz;
                ar = NULL;
                if (sz)
                    ar= new T[sz];
                else
                    ar = NULL;
                int o=0;
                if (sz)
                {
                    while ( o <(int) sz)
                    {
                        ar[o] = otherr.ar[o];
                        o++;
                    }
                }
        }


        unsigned int size() const
        {
            return sz;
        }


        T& operator[](unsigned int i)
        {
            if (i == 0 && ar == NULL)
		    	throw std::exception();

		    if (i >= sz)
		    	throw std::exception();
		    return ar[i];
	    }
    
        T& operator[](unsigned int i) const
        {
            if (ar == NULL && i == 0)
		    	throw std::exception();
            
		    if (i >= sz)
		    	throw std::exception();
		    return ar[i];
	    }

    private :
        T               *ar;
        unsigned int    sz;
};

#endif 