/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:44 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/20 17:01:01 by hyunjung         ###   ########.fr       */
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
void			occur_error(void);
void			input_validater(char *argv[]);
int				check_numbers(const char *str);
int				ft_isspace(char c);
int				get_str_size(char **str);
int				get_arr_size(int argc, char *argv[]);
void			free_str(char **str);
void			set_str_to_arr(int *arr, char **str, int *arr_count);
int				*get_new_arr(int argc, char *argv[], int size);
void			change_to_stack(t_stack_data *stack_data, int *arr, int size);
void			validate_arr(int *arr, int i, int size);
void			sort_stack(t_stack_data *stack_data);
#endif 