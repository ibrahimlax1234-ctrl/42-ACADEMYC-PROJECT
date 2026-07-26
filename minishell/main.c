/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:32:45 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/21 15:30:18 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char *av[], char **envp)
{
	t_g				*t;
	struct termios	settings;

	rl_catch_signals = 0;
	tcgetattr(STDIN_FILENO, &settings);
	t = init_global_struct(ac, av, envp);
	g_sig = 0;
	setup_signals();
	while (1)
	{
		if (!handle_input_line(t, &settings))
			break ;
	}
	cleanup(t);
	return (exit_status(0, 0));
}
