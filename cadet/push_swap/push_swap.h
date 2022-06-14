/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:44 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/14 18:08:02 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
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

void	occur_error(void);
void	input_validater(char *argv[]);
int		check_numbers(const char *str);
#endif 