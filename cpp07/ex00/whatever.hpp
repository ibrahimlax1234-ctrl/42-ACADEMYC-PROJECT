/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:02:35 by librahim          #+#    #+#             */
/*   Updated: 2025/11/18 19:52:04 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>


template <typename V> void swap(V &a, V &b)
{
    V temp = a;
    a = b;
    b = temp;
}

template <typename V> V &min(V &a, V &b)
{
    if (a < b)
        return a;

    else
        return b;
}


template <typename V> V &max(V &a, V &b)
{
    if (a > b)
        return a;
    else
        return b;
}

#endif