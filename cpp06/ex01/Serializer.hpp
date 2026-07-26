/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:53:54 by librahim          #+#    #+#             */
/*   Updated: 2025/11/15 16:25:09 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include "Data.hpp"


class Serializer
{
	private:
		Serializer();
		virtual ~Serializer();
		Serializer(Serializer &o);
		Serializer& operator=(Serializer &o);
	public:

		static uintptr_t serialize(Data* ptr);

	    static Data* deserialize(uintptr_t raw);
};

#endif