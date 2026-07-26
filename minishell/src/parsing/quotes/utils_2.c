/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:07:10 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/18 20:09:23 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	copy_quoted_segment_2(char *s, t_quote_data *data)
{
	char	quote;

	quote = s[data->i];
	data->i++;
	while (s[data->i] && s[data->i] != quote)
	{
		data->new[data->j] = s[data->i];
		data->j++;
		data->i++;
	}
	if (s[data->i])
		data->i++;
}
