/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:11:17 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/20 15:38:53 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	if (s1 == NULL)
		return (ft_strdup(""));
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	k = 0;
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[i] && ft_strchr(set, s1[j]))
		j--;
	if (i > j)
		return (ft_strdup(""));
	ptr = (char *)safe_malloc (sizeof(char) * (j - i + 2));
	if (!ptr)
		return (NULL);
	while (i <= j)
		ptr[k++] = s1[i++];
	ptr[k] = 0;
	return (ptr);
}
