/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:18:58 by librahim          #+#    #+#             */
/*   Updated: 2024/01/24 12:53:48 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *f, ...);
void	ft_printhex_len(unsigned int l, int *len);
void	ft_putchar_len(int k, int *len);
void	ft_putnbr_len(int nb, int *len);
void	ft_putnbr_u_len(unsigned int nb, int *len);
void	ft_putstr_len(char *s, int *len);
void	ft_printupperhex_len(unsigned int l, int *len);
void	ft_printadress_len(void *i, int *len);
#endif