/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:38:24 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/06 22:56:46 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_sigs(int signum)
{
	if (signum == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		if (waitpid(-1, NULL, WNOHANG) == 0)
			return ;
		rl_replace_line("", 0);
		rl_redisplay();
		exit_status(1, 1);
	}
	if (signum == SIGQUIT)
	{
		if (waitpid(-1, NULL, WNOHANG) != -1)
			ft_putstr_fd("Quit: 3\n", 1);
	}
}

void	setup_signals(void)
{
	signal(SIGINT, handle_sigs);
	signal(SIGQUIT, handle_sigs);
}
