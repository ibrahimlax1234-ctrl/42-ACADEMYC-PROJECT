/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:31:00 by librahim          #+#    #+#             */
/*   Updated: 2024/06/28 18:58:39 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(int k)
{
	write (1, &k, 1);
}

void	handlesig(int s, siginfo_t *t, void *a)
{
	static unsigned char	c;
	static int				ct;
	static int				new_pid;

	(void)a;
	if (new_pid != t->si_pid)
	{
		c = 0;
		ct = 0;
	}
	if (s == SIGUSR2)
		c = c | (1 << ct);
	ct++;
	if (ct == 8)
	{
		ft_putchar(c);
		c = 0;
		ct = 0;
	}
	new_pid = t->si_pid;
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.__sigaction_u.__sa_sigaction = handlesig;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}
