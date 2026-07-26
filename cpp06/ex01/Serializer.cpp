/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:58:53 by librahim          #+#    #+#             */
/*   Updated: 2025/11/15 20:22:38 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::~Serializer()
{}

Serializer::Serializer(Serializer &o)
{
    (void)o;
}

Serializer& Serializer::operator=(Serializer &o)
{
    (void)o;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t ret = reinterpret_cast<uintptr_t>(ptr);
    return ret;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* ret = reinterpret_cast<Data*>(raw);
	return ret;
}