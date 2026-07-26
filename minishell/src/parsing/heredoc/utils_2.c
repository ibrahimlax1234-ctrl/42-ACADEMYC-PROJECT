/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:10:34 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/18 20:14:17 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	calculate_size(char *str)
{
	int	size;
	int	k;

	size = 0;
	k = 0;
	while (str[k])
	{
		if (str[k] == '"' || str[k] == '\'')
			size += handle_quote_size(str, &k);
		else
			size += handle_normal_size(str, &k);
	}
	return (size + 1);
}

char	*process_quotes(char *str)
{
	int		size;
	int		k;
	int		c;
	char	*result;

	size = calculate_size(str);
	result = safe_malloc (size);
	if (!result)
		return (NULL);
	k = 0;
	c = 0;
	while (str[k])
	{
		if (str[k] == '"' || str[k] == '\'')
			copy_quoted_string(str, result, &k, &c);
		else
			copy_normal_characters(str, result, &k, &c);
	}
	result[c] = '\0';
	return (result);
}

void	handle_sigint_heredoc(int signum)
{
	if (signum == SIGINT)
	{
		g_sig = 1;
		close(0);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("\n", 2);
		exit_status(130, 1);
	}
}

void	write_input(int fd, char *input)
{
	ft_putstr_fd(input, fd);
	ft_putstr_fd("\n", fd);
}
