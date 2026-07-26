/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:09:29 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/18 20:03:35 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*remove_quotes(char *s)
{
	t_quote_data	data;

	data.i = 0;
	data.j = 0;
	data.len = ft_strlen(s);
	if (data.len == 0)
		return (NULL);
	data.new = safe_malloc(data.len + 1);
	while (s[data.i])
	{
		if (s[data.i] == '\'' || s[data.i] == '\"')
			copy_quoted_segment(s, &data);
		else
			copy_non_quoted_segment(s, &data);
	}
	data.new[data.j] = '\0';
	return (data.new);
}

char	*remove_quotes_2(char *s)
{
	t_quote_data	data;

	data.i = 0;
	data.j = 0;
	data.len = ft_strlen(s);
	if (data.len == 0)
		return (NULL);
	data.new = safe_malloc(data.len + 1);
	while (s[data.i])
	{
		if (s[data.i] == '\'' || s[data.i] == '\"')
			copy_quoted_segment_2(s, &data);
		else
			copy_non_quoted_segment(s, &data);
	}
	data.new[data.j] = '\0';
	return (data.new);
}
