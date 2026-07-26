/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librahim <librahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:32:49 by librahim          #+#    #+#             */
/*   Updated: 2024/07/02 22:38:28 by librahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <stdarg.h>

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
void	atoi_helper(char *str, int *j);

void	pb(t_s **a, t_s **b);
void	swap(t_s *lst, char c);

void	ss(t_s *a, t_s *b);
int		check_edges(long n);

void	rmlastspace(char *str);
void	rotate(t_s **lst, char c);

void	rrotate(t_s **lst, char c);
void	rr(t_s **a, t_s **b);

void	rrr(t_s **a, t_s **b);
int		ft_printf(const char *f, ...);

int		find_small(t_s *stack_a, int *ptr);
void	push_five(t_s **stack_a, t_s **stack_b);

void	p_err(void);
void	push_max_to_a(t_s **a, t_s **b);

void	push_to_b(t_s **a, t_s **b);
void	sort_three(t_s **s_a);

#endif