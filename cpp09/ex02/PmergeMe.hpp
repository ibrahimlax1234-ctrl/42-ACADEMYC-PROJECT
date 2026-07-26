/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 02:04:44 by librahim          #+#    #+#             */
/*   Updated: 2025/12/10 16:10:31 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>
#include <iomanip>
#include <sstream>


class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &o);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &o);
        static  std::vector<int>    parse_args(int argc, char **argv);
        static  void                run(int argc, char **argv);
        static  void sort_for_vec(std::vector<int>& arr);
        static  void sort_for_deq(std::deque<int>& arr);

};

#endif
