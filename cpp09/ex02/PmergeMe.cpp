/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 02:05:17 by librahim          #+#    #+#             */
/*   Updated: 2025/12/10 16:11:01 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &o) {(void)o;}
PmergeMe&	PmergeMe::operator=(const PmergeMe &o){(void)o;return(*this);}

int J(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return (J(n - 1) + 2 * J(n - 2));
}

std::vector<int> PmergeMe::parse_args(int ac, char **av)
{
    std::vector<int> a;
    int i = 0;

    while (++i < ac)
    {
        std::string arg = av[i];
        
		if (arg.size() == 0 || arg.find_first_not_of(" ") == std::string::npos)
        {
            std::cerr << "Error: empty arg or spaces only" << std::endl;
            throw std::exception();
        }
        std::stringstream ss(arg);
        std::string segment;
		ss >> segment;
        while (ss)
        {
            for (size_t j = 0; j < segment.size(); j++)
            {
				if (j == 0 && segment[j] == '+')
                    continue;
                if (!std::isdigit(static_cast<unsigned char>(segment[j])))
                {
                    std::cerr << "Error: invalid character " << std::endl;
                    throw std::exception();
                }
            }
            long val = std::atol(segment.c_str());
            if (val <= 0 || val > 2147483647)
            {
                std::cerr << "Error2: integer overflow or negative or null or invalid char" << std::endl;
                throw std::exception();
            }
            a.push_back(static_cast<int>(val));
			ss>>segment;
        }
    }
	return a;
}



void PmergeMe::run(int argc, char **argv)
{
	std::vector<int> starting_elements;
	starting_elements = parse_args(argc, argv);
	if (starting_elements.size() == 0)
		throw std::exception();
	std::deque<int> deq_start(starting_elements.begin(), starting_elements.end());
	std::cout << "Before:    " ;
	for (size_t i = 0; i < starting_elements.size(); i++)
		std::cout << starting_elements[i] <<" ";
	std::cout <<std::endl;
	

	struct timeval start_deq, stop_deq;
	struct timeval start_vec, stop_vec;

	gettimeofday(&start_vec, NULL); // vector chrono start t = 0;
	sort_for_vec(starting_elements);
	gettimeofday(&stop_vec, NULL);   // chrono stop


	gettimeofday(&start_deq, NULL); // deq chrono start t = 0;
	sort_for_deq(deq_start);
	gettimeofday(&stop_deq, NULL);  //  deq chrono stop

	long secs = stop_vec.tv_sec - start_vec.tv_sec;
    long usecs = stop_vec.tv_usec - start_vec.tv_usec;
    double timediff_vec = (secs * 1000000) + usecs;

	secs = stop_deq.tv_sec - start_deq.tv_sec;
    usecs = stop_deq.tv_usec - start_deq.tv_usec;
	double time_diff_deq = (secs * 1000000) + usecs;

	std::cout << "After:     " ;
	for (size_t i = 0; i < starting_elements.size(); i++)
		std::cout << starting_elements[i] <<" ";
	std::cout <<std::endl;

	std::cout << "Time to process a range of  " << starting_elements.size() << " elements with std::vector<int> : "<<std::fixed <<std::setprecision(3) << timediff_vec <<" us" <<std::endl;
	std::cout << "Time to process a range of  " <<  starting_elements.size() << " elements with std::deque<int> : " << std::fixed<<std::setprecision(3) << time_diff_deq <<" us" <<std::endl;
}
























/// VEC
























std::vector<std::pair<int,int> > make_sortedpairs(std::vector<int> arr)
{
	std::vector<std::pair<int, int> > pairs;

	size_t i = 0;
	while (i < arr.size())
	{
		std::pair<int, int> p;
		if (i + 1 < arr.size())
		{
			if (arr[i] >= arr[i+1])
			{
				p.first = arr[i];
				p.second = arr[i+1];
			}
			else
			{
				p.first = arr[i+1];
				p.second = arr[i];
			}
			pairs.push_back(p);
		}
		i = i+2;
	}
	return pairs;
}


std::vector<int> rearrangeindx(std::vector<std::pair<int,int> > d, std::vector<int> winners_queue)
{
	std::vector<int> res;
	size_t i = 0;

	while (i < winners_queue.size())
	{
		for (size_t j = 0; j < d.size();j++)
		{
			if (winners_queue[i] == d[j].first)
			{
				res.push_back(d[j].second);
				break ;
			}
		}
		i++;
	}
	return res;
}

void insert_merge(std::vector<int> &main_ch, const std::vector<int> &other_half)
{
	std::vector<int> tmp(main_ch);
	main_ch.insert(main_ch.begin(), other_half[0]);
    size_t last_inserted_idx = 0;
	size_t i = 4;
	while (true)
    {
		if (last_inserted_idx + 1 >= other_half.size())
            break;
        size_t current_pos = J(i);
        if (current_pos >= other_half.size())
            current_pos = other_half.size();
        for (size_t j = current_pos - 1; j > last_inserted_idx; j--)
        {
            if (j >= other_half.size())
                continue;
            int partner = tmp[j];
            std::vector<int>::iterator interval_end = std::find(main_ch.begin(), main_ch.end(), partner);
            std::vector<int>::iterator insrt_pos = std::upper_bound(main_ch.begin(), interval_end, other_half[j]);
            main_ch.insert(insrt_pos, other_half[j]);
        }
        last_inserted_idx = current_pos ;
		i++;
    }
}

void PmergeMe::sort_for_vec(std::vector<int>& arr)
{
	int lone_element = -1;
	if (arr.size() == 1)
		return;
	if (arr.size() % 2 != 0)
	{
		lone_element = arr[arr.size() - 1];
		arr.pop_back();
	}
	std::vector<std::pair<int, int> > pairs = make_sortedpairs(arr);
	std::vector<int> superior_elments;
	for (size_t i=0; i < pairs.size();i++)
        superior_elments.push_back(pairs[i].first);
	PmergeMe::sort_for_vec(superior_elments);
	std::vector<int> other_half = rearrangeindx(pairs ,superior_elments);
	insert_merge(superior_elments, other_half);
	if (lone_element != -1)
	{
    	std::vector<int>::iterator pos = std::upper_bound(superior_elments.begin(), superior_elments.end(), lone_element);
    	superior_elments.insert(pos, lone_element);
	}
	arr = superior_elments;
}



























////// DEQ



















std::deque<std::pair<int,int> > make_sortedpairs_deq(std::deque<int> arr)
{
	std::deque<std::pair<int, int> > pairs;

	size_t i = 0;
	while (i < arr.size())
	{
		std::pair<int, int> p;
		if (i + 1 < arr.size())
		{
			if (arr[i] >= arr[i+1])
			{
				p.first = arr[i];
				p.second = arr[i+1];
			}
			else
			{
				p.first = arr[i+1];
				p.second = arr[i];
			}
			pairs.push_back(p);
		}
		i = i+2;
	}
	return pairs;
}


std::deque<int> rearrangeindx_deq(std::deque<std::pair<int,int> > d, std::deque<int> winners_queue)
{
	std::deque<int> res;
	size_t i = 0;

	while (i <winners_queue.size())
	{
		for (size_t j = 0; j < d.size();j++)
		{
			if (winners_queue[i] == d[j].first)
			{
				res.push_back(d[j].second);
				break ;
			}
		}
		i++;
	}
	return res;
}


void insert_merge_deq(std::deque<int> &main_ch, const std::deque<int> &other_half)
{
	std::deque<int> tmp(main_ch);
	main_ch.insert(main_ch.begin(), other_half[0]);
    size_t last_inserted_idx = 0;
	size_t i = 4;
	while (true)
    {
		if (last_inserted_idx + 1 >= other_half.size())
            break;
        size_t current_pos = J(i);
        if (current_pos >= other_half.size())
            current_pos = other_half.size();

        for (size_t j = current_pos - 1; j > last_inserted_idx; j--)
        {
            if (j >= other_half.size())
                continue;
            int partner = tmp[j];
            std::deque<int>::iterator interval_end = std::find(main_ch.begin(), main_ch.end(), partner);
            std::deque<int>::iterator insrt_pos = std::upper_bound(main_ch.begin(), interval_end, other_half[j]);
            main_ch.insert(insrt_pos, other_half[j]);
        }
        last_inserted_idx = current_pos ;
		i++;
    }
}


void PmergeMe::sort_for_deq(std::deque<int>& arr)
{	
	int lone_element = -1;

	if (arr.size() == 1)
		return;
	if (arr.size() % 2 != 0)
	{
		lone_element = arr[arr.size() - 1];
		arr.pop_back();
	}
	std::deque<std::pair<int, int> > pairs = make_sortedpairs_deq(arr);
	std::deque<int> superior_elments;
	for (size_t i=0; i < pairs.size();i++)
        superior_elments.push_back(pairs[i].first);
	PmergeMe::sort_for_deq(superior_elments);
	std::deque<int> other_half = rearrangeindx_deq(pairs ,superior_elments);
	insert_merge_deq(superior_elments, other_half);
	if (lone_element != -1)
	{
    	std::deque<int>::iterator pos = std::upper_bound(superior_elments.begin(), superior_elments.end(), lone_element);
    	superior_elments.insert(pos, lone_element);
	}
	arr = superior_elments;
}
