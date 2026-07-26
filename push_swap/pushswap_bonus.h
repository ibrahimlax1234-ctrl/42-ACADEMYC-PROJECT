/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 05:07:51 by librahim          #+#    #+#             */
/*   Updated: 2024/07/09 08:26:58 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_s
{
	long		value;
	int			pos;
	struct s_s	*next;
}	t_s;

int		ft_printf(const char *f, ...);
void	ft_printhex_len(unsigned int l, int *len);

void	ft_putchar_len(int k, int *len);
void	ft_putnbr_len(int nb, int *len);

void	ft_putnbr_u_len(unsigned int nb, int *len);
void	ft_putstr_len(char *s, int *len);

void	ft_printupperhex_len(unsigned int l, int *len);
void	ft_printadress_len(void *i, int *len);

int		space_detector_at_the_end(char *s);
int		ft_strlen(char *s);

int		ft_cust_atoi(char *str, long *nbr, int *j);
char	*ft_strdup(char *s);

void	atoi_helper(char *str, int *j);
char	*ft_strjoin(char *s1, char *s2);
int		checkspace(char *arg);

char	*joineverything(char **argv, int argc);
int		checkargs(char *lstr);

long	fetsh(char *res, int *j, int *flag);
char	*parse(int argc, char **argv);

t_s		*newlist(int value);
int		lstsize(t_s *lst);

void	addfront(t_s **lst, t_s *new);
void	addback(t_s **lst, t_s *new);

int		duplicate_detection(t_s *h);
t_s		*fill(int argc, char **argv);

void	rm_last_one(t_s **lst);
void	free_stack(t_s *s);

int		is_stack_sorted(t_s *s);
void	indexing(t_s *stack_a, t_s *node);

void	pa(t_s **b, t_s **a);
void	pb(t_s **a, t_s **b);

void	swap(t_s *lst);
void	ss(t_s *a, t_s *b);

int		check_edges(long n);
void	rmlastspace(char *str);

void	rotate(t_s **lst);
void	rrotate(t_s **lst);

void	rr(t_s **a, t_s **b);
void	rrr(t_s **a, t_s **b);

int		ft_printf(const char *f, ...);
void	p_err(void);

void	push_max_to_a(t_s **a, t_s **b);
void	push_to_b(t_s **a, t_s **b);

void	handle_swap(char *s, t_s **a, t_s **b);
void	handle_rot(char *s, t_s **a, t_s **b);

void	handle_rrot(char *s, t_s **a, t_s **b);
void	handle_push(char *s, t_s **a, t_s **b);

int		checkit(char *s, t_s **a, t_s **b);
char	*ftr_strchr(char *s, int c);

char	*get_next_line(int fd);
char	*ft_read(char *mainbuffer, int fd, int *index);

char	*ftr_substr(char *s, unsigned int start, size_t len);
char	*ftr_strjoin(char *s1, char *s2);

char	*ftr_strdup(char *s);
size_t	ftr_strlen(char *s);

void	*ftr_calloc(size_t blocks, size_t sizeblock);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif