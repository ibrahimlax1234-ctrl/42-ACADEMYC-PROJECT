/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:05:46 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/11 01:36:30 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../minishell.h"

int	print_invalid_id_error(char *key)
{
	ft_putstr_fd("minishell : `", 2);
	ft_putstr_fd(key, 2);
	ft_putstr_fd("' : not a valid identifier\n", 2);
	return (exit_status(1, 1), 1);
}

void	swap_env_data(t_env *a, t_env *b)
{
	char	*temp_key;
	char	*temp_data;

	temp_key = a->key;
	temp_data = a->data;
	a->key = b->key;
	a->data = b->data;
	b->key = temp_key;
	b->data = temp_data;
}
