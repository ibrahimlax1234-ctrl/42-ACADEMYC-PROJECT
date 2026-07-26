/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:48:43 by librahim          #+#    #+#             */
/*   Updated: 2024/02/18 01:14:52 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*ft_strchr_b(char *s, int c);
char	*get_next_line(int fd);
char	*ft_read_b(char *mainbuffer, int fd, int *index);
char	*ft_substr_b(char *s, unsigned int start, size_t len);
char	*ft_strjoin_b(char *s1, char *s2);
char	*ft_strdup_b(char *s);
size_t	ft_strlen_b(char *s);
void	*ft_calloc_b(size_t blocks, size_t sizeblock);
#endif