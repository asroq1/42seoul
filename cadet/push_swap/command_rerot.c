/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rerot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:06:59 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/21 12:24:38 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_data *a)
{
	t_node	*tmp;

	if (a->size_a < 2)
		occur_error(2);
	tmp = a->a_bottom;
	a->a_bottom->next = NULL;
	tmp->next = a->a_top;
	a->a_top = tmp;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack_data *b)
{
	t_node	*tmp;

	if (b->size_b < 2)
		occur_error(2);
	tmp = b->b_bottom;
	b->b_bottom->next = NULL;
	tmp->next = b->b_top;
	b->b_top = tmp;
	ft_putstr_fd("rra\n", 1);
}

void	rrr(t_stack_data *stacks)
{
	t_node	*tmp;

	if (stacks->size_a < 2 || stacks->size_b < 2)
		occur_error(2);
	tmp = stacks->a_bottom;
	stacks->a_bottom->next = NULL;
	tmp->next = stacks->a_top;
	stacks->a_top = tmp;
	tmp = stacks->b_bottom;
	stacks->b_bottom->next = NULL;
	tmp->next = stacks->b_top;
	stacks->b_top = tmp;
	ft_putstr_fd("rrr\n", 1);
}
