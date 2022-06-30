/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:44 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/30 20:21:30 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack_data
{
	int	*arr;
	int	length;
	int	total;
}	t_stack_data;

/* utils.c */
int				ft_isspace(char c);
void			occur_error(int err);
void			free_str(char **str);

/* validter.c */
int				check_input(t_stack_data *stack);
void			check_duplicate(t_stack_data *stack);
void			free_arr(char **arr);
void			input_validater(t_stack_data *stack, char *argv[]);
int				check_numbers(const char *str);
long long		ps_atoi(char *arr);

/* stack.c */
void			get_stack(t_stack_data *stack);
void			get_a(t_stack_data *stack, int n);
void			get_b(t_stack_data *stack, int length);

/* sort.c */
int				get_top(t_stack_data *stack);
int				get_mid(t_stack_data *stack);
int				get_bot(t_stack_data *stack);
void			sort_two_three(t_stack_data *stack);
void			small_command(t_stack_data *a, t_stack_data *b);
void			large_command(t_stack_data *a, t_stack_data *b);
void			a_to_b(t_stack_data *a, t_stack_data *b, int chunk, int i);
void			b_to_a(t_stack_data *b, t_stack_data *a);
void			sort_b(t_stack_data *b, int size);

/* array.c */

void			indexing_arr(t_stack_data *a);
void			sort_stack(t_stack_data *a, t_stack_data *b);

/* command.c */
// int				swap(t_stack_data *stack);
// int				push(t_stack_data *from, t_stack_data *dest);
// int				pa(t_stack_data *a, t_stack_data *b);
// int				pb(t_stack_data *a, t_stack_data *b);
// int				sa(t_stack_data *stack);
// int				sb(t_stack_data *stack);
// int				ss(t_stack_data *a, t_stack_data *b);

/* command_rot.c */
// int				rotate(t_stack_data *stack);
// int				ra(t_stack_data *stack);
// int				rb(t_stack_data *stack);
// int				rr(t_stack_data *a, t_stack_data *b);

/* command_rerot.c */
// int				rerotate(t_stack_data *stack);
// int				rra(t_stack_data *stack);
// int				rrb(t_stack_data *stack);
// int				rrr(t_stack_data *a, t_stack_data *b);

/* tmp */

int	sa(t_stack_data *a);
int	sb(t_stack_data *b);
int	ss(t_stack_data *a, t_stack_data *b);
int	pa(t_stack_data *a, t_stack_data *b);
int	pb(t_stack_data *a, t_stack_data *b);
int	ra(t_stack_data *a);
int	rb(t_stack_data *b);
int	rr(t_stack_data *a, t_stack_data *b);
int	rra(t_stack_data *a);
int	rrb(t_stack_data *b);
int	swap(t_stack_data *from);
int	push(t_stack_data *from, t_stack_data *to);
int	reverse_rotate(t_stack_data *from);
int	rotate(t_stack_data *from);

#endif 