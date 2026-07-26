/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:30:29 by librahim          #+#    #+#             */
/*   Updated: 2024/06/28 19:11:12 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	size_t	i;
	long	res;
	int		neg;

	res = 0;
	neg = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * neg);
}

int	main(int argc, char *argv[])
{
	int				pid;
	int				i;
	int				shift;
	unsigned char	c;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
		{
			c = argv[2][i];
			shift = 8;
			while (shift--)
			{
				if ((c << shift) & 128)
					kill(pid, SIGUSR2);
				else
					kill(pid, SIGUSR1);
				usleep(500);
			}
			i++;
		}
	}
	return (0);
}
