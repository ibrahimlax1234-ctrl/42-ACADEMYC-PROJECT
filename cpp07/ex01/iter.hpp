/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:53:42 by librahim          #+#    #+#             */
/*   Updated: 2025/11/21 01:58:31 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITER_HPP
#define ITER_HPP

template <typename Y> void	iter(Y* ar, const int len, void (*fct)(const Y&))
{
	int i = 0;
	while (i < len)
	{
		fct(ar[i]);
		i++;
	}
}

template <typename U> void	iter(U* ar, const int len, void (*fct)(U&))
{
	int i = 0;
	while (i < len)
	{
		fct(ar[i]);
		i++;
	}
}


#endif