/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:19:00 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/06 23:48:17 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	handle_quotes(const char *s, t_send_cmd *cmd)
{
	cmd->q = s[cmd->i];
	cmd->str[cmd->j++] = s[cmd->i++];
	while (s[cmd->i] && s[cmd->i] != cmd->q)
		cmd->str[cmd->j++] = s[cmd->i++];
	if (s[cmd->i] == cmd->q)
		cmd->str[cmd->j++] = s[cmd->i++];
}

void	handle_special_characters(const char *s, t_send_cmd *cmd)
{
	cmd->str[cmd->j++] = ' ';
	cmd->str[cmd->j++] = s[cmd->i++];
	if (s[cmd->i] == s[cmd->i - 1])
		cmd->str[cmd->j++] = s[cmd->i++];
	cmd->str[cmd->j++] = ' ';
}

void	process_characters(const char *s, t_send_cmd *cmd)
{
	while (s[cmd->i])
	{
		if (s[cmd->i] == '"' || s[cmd->i] == '\'')
			handle_quotes(s, cmd);
		else if (s[cmd->i] != '|' && s[cmd->i] != '<' && s[cmd->i] != '>')
			cmd->str[cmd->j++] = s[cmd->i++];
		else
			handle_special_characters(s, cmd);
	}
}
