/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:19:17 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/21 15:05:49 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static int	check_full_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

static int	check_syntax(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		i--;
	if (i < 0)
		return (0);
	if (s[i] == '|' || s[i] == '<' || s[i] == '>')
		return (1);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] == '|')
		return (1);
	i = 0;
	if (s[i] == '|')
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if (s[i] == '|')
			return (1);
	}
	return (0);
}

static int	check_quotes(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (check_invalid_pipes(s, &i))
			return (1);
		if (check_double_quotes(s, &i))
			return (1);
		if (check_single_quotes(s, &i))
			return (1);
		if (s[i])
			i++;
	}
	return (0);
}

int	some_checks_before_parse(char *rl)
{
	if (check_full_spaces(rl))
	{
		exit_status(0, 1);
		return (1);
	}
	if (check_syntax(rl))
	{
		exit_status(258, 1);
		ft_putstr_fd("minishell : syntax error\n", 2);
		return (1);
	}
	if (check_quotes(rl))
	{
		exit_status(258, 1);
		ft_putstr_fd("minishell : syntax error\n", 2);
		return (1);
	}
	return (0);
}
