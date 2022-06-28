/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:44 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/28 16:12:53 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_node
{
	struct s_node	*next;
	int				content;
}	t_node;

typedef struct s_stack_data
{
	int				*arr;
	int				size_a;
	int				size_b;
	struct s_node	*a_top;
	struct s_node	*a_bottom;
	struct s_node	*b_top;
	struct s_node	*b_bottom;
}	t_stack_data;

t_node			*make_new_stack(void);
t_stack_data	*get_new_stacks(void);
void			occur_error(int err);
void			input_validater(char *argv[]);
int				check_numbers(const char *str);
int				ft_isspace(char c);
int				get_str_size(char **str);
int				get_arr_size(int argc, char *argv[]);
void			free_str(char **str);
void			set_str_to_arr(int *arr, char **str, int *arr_count);
int				*get_new_arr(int argc, char *argv[], int size);
void			change_to_stack(t_stack_data *stack_data, int *arr, int size);
void			indexing_arr(t_stack_data *a, int *arr, int count);
void			sort_stack(t_stack_data *a, t_stack_data *b);
void			sa(t_stack_data *a);
void			sb(t_stack_data *b);
void			ss(t_stack_data *stacks);
void			pa(t_stack_data *node);
void			pb(t_stack_data *node);
void			ra(t_stack_data *a);
void			rb(t_stack_data *b);
void			rr(t_stack_data *stacks);
void			rra(t_stack_data *a);
void			rrb(t_stack_data *b);
void			rrr(t_stack_data *stacks);
int				ft_get_bigger(int a, int b, int a_pos, int b_pos);
int				get_stack_min(t_node *a);
int				get_stack_max(t_node *a);
// int				set_a_position(int n, t_stack_data *stack);
// int				set_a_position_min(t_stack_data *stack);
// int				set_a_position_mid(t_stack_data *stack);
// int				set_a_position_max(t_stack_data *stack);
void			a_to_b(t_stack_data *a, t_stack_data *b, int chunk, int i);
void			b_to_a(t_stack_data *b, t_stack_data *a);
void			sort_b(t_stack_data *b, int size);
void			make_b_stack(t_stack_data *b);

#endif 