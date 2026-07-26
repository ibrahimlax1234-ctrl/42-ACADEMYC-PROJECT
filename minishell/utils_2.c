/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:47:38 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/18 20:32:03 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup(t_g *t)
{
	(void)t;
	if (t)
		free(t->rl_line);
	safe_free();
	if (isatty(STDOUT_FILENO))
		ft_putstr_fd("exit\n", 2);
}

t_env	*create_empty_env(void)
{
	char	*name;
	char	*data;
	t_env	*new_node;
	t_env	*head;

	head = NULL;
	name = ft_strdup("PWD");
	data = ft_strdup(find_pwd());
	new_node = ft_lstnew_env(name, data);
	ft_lstadd_back_env(&head, new_node);
	name = ft_strdup("SHLVL");
	data = ft_strdup("1");
	new_node = ft_lstnew_env(name, data);
	ft_lstadd_back_env(&head, new_node);
	name = ft_strdup("_");
	data = ft_strdup("/usr/bin/env");
	new_node = ft_lstnew_env(name, data);
	ft_lstadd_back_env(&head, new_node);
	name = ft_strdup("PATH");
	data = ft_strdup("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.");
	new_node = ft_lstnew_env(name, data);
	ft_lstadd_back_env(&head, new_node);
	return (head);
}

t_env	*create_empty_exp(void)
{
	char	*name;
	char	*data;
	t_env	*new_node;
	t_env	*head;

	head = NULL;
	name = ft_strdup("OLDPWD");
	data = ft_strdup("\0");
	new_node = ft_lstnew_env(name, data);
	ft_lstadd_back_env(&head, new_node);
	name = ft_strdup("PWD");
	data = ft_strdup(find_pwd());
	new_node = ft_lstnew_env(name, data);
	ft_lstadd_back_env(&head, new_node);
	name = ft_strdup("SHLVL");
	data = ft_strdup("1");
	new_node = ft_lstnew_env(name, data);
	ft_lstadd_back_env(&head, new_node);
	return (head);
}

void	reset_data(t_g *t)
{
	t->rl_line = NULL;
	t->cmd_nbr = 0;
	t->cmd_head = NULL;
	t->pipe_fds = NULL;
}
