/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:06:50 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/07 01:56:51 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_cmd	*ft_lstnew(char **command)
{
	t_cmd	*new;

	new = safe_malloc (sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->command = command;
	new->next = NULL;
	new->fd_in = dup(STDIN_FILENO);
	new->fd_out = dup(STDOUT_FILENO);
	return (new);
}

t_env	*ft_lstnew_env(char *name, char *data)
{
	t_env	*new;

	new = safe_malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = name;
	if (data)
		new->data = data;
	new->next = NULL;
	return (new);
}
