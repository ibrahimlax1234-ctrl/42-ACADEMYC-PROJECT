/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:16:52 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/18 20:09:13 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	is_redirection_operator(char *s, int start)
{
	if (s[start] == '>' && s[start + 1] == '>')
		return (2);
	if (s[start] == '<' && s[start + 1] == '<')
		return (2);
	if (s[start] == '>' || s[start] == '<')
		return (1);
	return (0);
}

void	copy_redirection(char *s, t_quote_data *data, char quote)
{
	data->new[data->j] = s[data->i];
	data->j++;
	data->i++;
	while (s[data->i] && s[data->i] != quote)
	{
		data->new[data->j] = s[data->i];
		data->j++;
		data->i++;
	}
	if (s[data->i])
	{
		data->new[data->j] = s[data->i];
		data->j++;
		data->i++;
	}
}

void	copy_normal_segment(char *s, t_quote_data *data, char quote)
{
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

void	copy_non_quoted_segment(char *s, t_quote_data *data)
{
	data->new[data->j] = s[data->i];
	data->j++;
	data->i++;
}

void	copy_quoted_segment(char *s, t_quote_data *data)
{
	char	quote;
	int		start;
	int		is_redir;

	quote = s[data->i];
	start = data->i + 1;
	is_redir = is_redirection_operator(s, start);
	if (is_redir)
		copy_redirection(s, data, quote);
	else
		copy_normal_segment(s, data, quote);
}
