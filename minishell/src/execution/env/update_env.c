/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:53:08 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/11 01:03:58 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	update_env(t_g *t)
{
	t_env		*current;
	int			i;

	current = t->env;
	while (current)
	{
		if (!ft_strcmp(current->key, "_"))
		{
			i = 0;
			while (t->cmd_head->command[i + 1])
				i++;
			if (!ft_strcmp(t->cmd_head->command[i], "$_"))
				break ;
			else
			{
				current->data = ft_strdup(t->cmd_head->command[i]);
				break ;
			}
		}
		current = current->next;
	}
}
