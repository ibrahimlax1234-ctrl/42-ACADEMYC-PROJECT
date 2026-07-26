/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:58:54 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/07 01:20:08 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_gc	**get_safe_head(void)
{
	static t_gc	*safe_head;

	return (&safe_head);
}

void	*safe_malloc(size_t size)
{
	void	*ptr;
	t_gc	*new_node;
	t_gc	**safe_head;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	safe_head = get_safe_head();
	new_node = malloc(sizeof(t_gc));
	if (!new_node)
		return (NULL);
	new_node->ptr = ptr;
	new_node->next = *safe_head;
	*safe_head = new_node;
	return (ptr);
}

void	safe_free(void)
{
	t_gc	**safe_head;
	t_gc	*current;
	t_gc	*temp;

	safe_head = get_safe_head();
	current = *safe_head;
	while (current)
	{
		if (current->ptr)
		{
			free(current->ptr);
			current->ptr = NULL;
		}
		temp = current;
		current = current->next;
		free(temp);
	}
	*safe_head = NULL;
}
