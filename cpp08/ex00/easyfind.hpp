/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:26:37 by librahim          #+#    #+#             */
/*   Updated: 2025/11/28 21:19:25 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <string>
#include <iostream>
#include <exception>
#include <algorithm>


template <typename T> void easyfind(T &cnt, int to_find)
{
    typename T::iterator a;
    a = std::find(cnt.begin(), cnt.end(), to_find);
    if (a == cnt.end())
        throw std::exception();
}

#endif