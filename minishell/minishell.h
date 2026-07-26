/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:33:16 by mkobaa            #+#    #+#             */
/*   Updated: 2024/12/21 15:30:23 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <paths.h>
# include <dirent.h>
# include <termios.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

int	g_sig;

typedef struct s_quote_data
{
	int		i;
	int		j;
	int		len;
	char	*new;
}	t_quote_data;

typedef struct s_gc
{
	void		*ptr;
	struct s_gc	*next;
}	t_gc;

typedef struct s_command
{
	char				**command;
	int					fd_out;
	int					fd_in;
	char				*heredoc_cmd;
	struct s_command	*next;
}	t_cmd;

typedef struct s_env
{
	char			*key;
	char			*data;
	struct s_env	*next;
}	t_env;

typedef struct s_expand
{
	int		i;
	char	*new_value;
	int		new_length;
	int		m;
	int		data_length;
	char	*data;
	int		k;
	char	*var;
	int		j;
	int		p;
	char	*status;
}		t_expand;

typedef struct s_split_quotes
{
	int		count;
	char	**splitted;
	int		i;
	char	quote;
	int		k;
}		t_split_quotes;

typedef struct s_global
{
	char	*rl_line;
	int		cmd_nbr;
	int		**pipe_fds;
	t_env	*env;
	t_cmd	*cmd_head;
}	t_g;

typedef struct s_send_cmd
{
	char	*str;
	int		j;
	int		i;
	int		str_len;
	char	q;
}			t_send_cmd;

void		handle_sigs(int signum);
void		setup_signals(void);
void		cleanup(t_g *t);
int			handle_input_line(t_g *t, struct termios *settings);
t_g			*init_global_struct(int ac, char **av, char **env);
void		*safe_malloc(size_t size);
void		safe_free(void);
t_env		*create_env(char **envp);
int			ft_atoi(const char *str);
int			ft_strcmp(char *s1, char *s2);
char		*to_lower(char *s);
char		*ft_itoa(int n);
t_env		*ft_lstnew_env(char *name, char *data);
void		ft_lstadd_back_env(t_env **lst, t_env *new);
t_env		*create_exp(char **env);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
int			some_checks_before_parse(char *rl);
int			exit_status(int new_stat, int set);
int			check_invalid_pipes(char *s, int *i);
int			check_double_quotes(char *s, int *i);
int			check_single_quotes(char *s, int *i);
size_t		ft_strlen(const char *s);
int			ft_lstsize_env(t_env *env);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
char		**env_2d(t_env *env);
t_cmd		*create_command(char *s, t_cmd *cmd);
void		ft_lstadd_back(t_cmd **lst, t_cmd *new);
t_cmd		*ft_lstnew(char **command);
char		**ft_strtrok(char *s, char c);
void		handle_quotes(const char *s, t_send_cmd *cmd);
void		handle_special_characters(const char *s, t_send_cmd *cmd);
void		process_characters(const char *s, t_send_cmd *cmd);
int			check_empty_command(t_cmd *cmd);
int			check_trailing_operator(char **command);
int			check_consecutive_operators(char **command);
int			some_checks_after_parse(t_cmd *cmd);
int			check_syntax_command(t_cmd *cmd);
void		update_env(t_g *t);
void		ft_expansion(t_cmd *cmd, t_env *env);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
char		*get_from_env(char *var, t_env **env);
char		*ft_expand(char *s, t_env *env);
char		**split_quotes(char *s);
char		*remove_quotes(char *s);
int			calculate_required_length(char *s, t_env *env);
void		handle_non_expansion_case(char **sp, char **s);
void		copy_quoted_segment(char *s, t_quote_data *data);
void		copy_non_quoted_segment(char *s, t_quote_data *data);
int			ft_append(t_cmd *cmd, int i);
int			ft_input(t_cmd *cmd, int i);
int			ft_output(t_cmd *cmd, int i);
void		ft_redirection(t_cmd *cmd, t_env *env);
int			ft_heredoc(t_cmd *cmd, int i, int fd, t_env *env);
int			copy_quoted_string(char *str, char *result, int *k, int *c);
int			copy_normal_characters(char *str, char *result, int *k, int *c);
int			handle_quote_size(char *str, int *k);
int			handle_normal_size(char *str, int *k);
int			cmd_nbr(t_cmd *head);
void		launch_execution(t_g *t);
int			is_builtin(char *cmd);
void		ft_exec_single_builtin(t_g *t);
void		ft_echo(t_cmd *cmd, t_g *t);
int			ft_pwd(t_cmd *cmd, t_g *t);
void		ft_cd(t_cmd *cmd, t_env *env, t_g *t);
char		*find_pwd(void);
int			ft_exit(t_cmd *cmd, t_g *t);
long long	ft_atoll(char *str);
int			ft_isnumber(char *str);
char		*ft_strtrim(char const *s1, char const *set);
void		ft_env(t_env *env, t_g *t);
void		ft_export(t_cmd *cmd, t_env *env);
void		ft_putendl_fd(char *s, int fd);
int			ft_isalnum(int c);
void		ft_unset(t_cmd *cmd, t_env **env);
void		fork_one_cmd(t_g *t);
void		check_error(char *cmd);
void		oc_starting_point_slash(t_cmd *cmd, t_env *env);
void		oc_bin_only(t_cmd *cmd, t_env *env);
char		**ft_split(char const *s, char c);
int			is_directory(const char *path);
void		ft_fork_execve(t_g *t, t_cmd *cmd_to_exec);
void		handle_dup_fork_ii(t_g *t, t_cmd *c, int cmd_count);
void		handle_dup_fork(t_g *t, t_cmd *c, int cmd_count);
void		close_fds_helper(t_g *t);
int			fork_and_exec(t_g *t, t_cmd *c, int cmd_count);
void		iter_close_fds(t_cmd *h);
void		close_free_pipes(int **pipe_ends, int i);
void		ft_exec_fork_builtin(t_g *t, t_cmd *cmd_ptr);
void		pipe_starting_point_slash(t_cmd *cmd, t_env *env);
void		pipe_bin_only(t_cmd *cmd, t_env *env);
char		**get_path(t_env *e, char *cmd);
void		mc_error_path_msg(t_cmd *cmd);
void		handle_mult_pipes(t_g *t);
int			is_redirection_operator(char *s, int start);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*remove_quotes_2(char *s);
void		copy_quoted_segment_2(char *s, t_quote_data *data);
int			process_command(t_cmd *cmd, t_env *env);
void		remove_redirection_quotes(t_cmd *cmd);
int			handle_heredoc(t_cmd *cmd, int i, t_env *env, int *len);
int			handle_input_redirection(t_cmd *cmd, int i, int *len);
int			handle_output_redirection(t_cmd *cmd, int i, int *len);
int			handle_append_redirection(t_cmd *cmd, int i, int *len);
int			is_quoted_string(char *str);
t_env		*create_empty_exp(void);
t_env		*create_empty_env(void);
char		*find_key(char *s);
char		*find_data(char *s);
void		print_exported_env(t_env *exp);
int			count_word(const char *s, char c);
void		replace_char(char **s);
int			check_valid_id(char *key);
void		sort_list(t_env *env);
int			print_invalid_id_error(char *key);
void		swap_env_data(t_env *a, t_env *b);
void		handle_sigint_heredoc(int signum);
char		*process_quotes(char *str);
void		write_input(int fd, char *input);
void		close_pipe_fds(t_g *t, int cmd_count);
void		close_command_fds(t_cmd *cmd_ptr);
void		reset_data(t_g *t);
int			is_valid_var_char(char c);
int			handle_exit_status(char *s, t_expand *e);
int			skip_special_cases(char *s, t_expand *e);

#endif
