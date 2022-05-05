/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:44 by hyunjung          #+#    #+#             */
/*   Updated: 2022/05/05 17:09:48 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_info
{
	int				*arr;
	int				size_a;
	int				size_b;
	struct s_node	*a_top;
	struct s_node	*a_bottom;
	struct s_node	*b_top;
	struct s_node	*b_bottom;
}	t_info;

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				content;
}	t_node;

  /* utils.c */
void	occur_error(void)

#endif 