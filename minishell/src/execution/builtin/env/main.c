/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:03:03 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/21 09:31:58 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../minishell.h"

void	ft_env(t_env *env, t_g *t)
{
	(void)t;
	while (env)
	{
		if (env->data && env->data[0] != '\2')
			printf("%s=%s\n", env->key, env->data);
		env = env->next;
	}
}
