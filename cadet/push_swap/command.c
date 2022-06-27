/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:32:11 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/27 12:54:17 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_data *a)
{
	int	tmp;

	if (a->size_a < 2)
	{
		return ;
	}
	tmp = a->a_top->content;
	a->a_top->content = a->a_top->next->content;
	a->a_top->next->content = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack_data *b)
{
	int	tmp;

	if (b->size_b < 2)
	{
		return ;
	}
	tmp = b->b_top->content;
	b->b_top->content = b->b_top->next->content;
	b->b_top->next->content = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack_data *stacks)
{
	int	tmp;

	if (stacks->size_a < 2)
	{
		return ;
	}
	if (stacks->size_b < 2)
	{
		return ;
	}
	tmp = stacks->a_top->content;
	stacks->a_top->content = stacks->a_top->next->content;
	stacks->a_top->next->content = tmp;
		tmp = stacks->b_top->content;
	stacks->b_top->content = stacks->b_top->next->content;
	stacks->b_top->next->content = tmp;
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack_data *node)
{
	t_node	*tmp;

	if (node->size_b < 1)
		return ;
	tmp = node->b_top;
	if (node->size_b > 1)
		node->b_top = node->b_top->next;
	if (node->size_a == 0)
	{
		tmp->next = 0;
		node->a_top = tmp;
		node->a_bottom = tmp;
	}
	else
	{
		tmp->next = node->a_top;
		node->a_top = tmp;
	}
	node->size_a++;
	node->size_b--;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack_data *node)
{
	t_node	*tmp;

	if (node->size_b < 1)
		return ;
	tmp = node->a_top;
	if (node->size_b > 1)
		node->a_top = node->a_top->next;
	if (node->size_b == 0)
	{
		tmp->next = 0;
		node->b_top = tmp;
		node->b_bottom = tmp;
	}
	else
	{
		tmp->next = node->b_top;
		node->b_top = tmp;
	}
	node->size_a--;
	node->size_b++;
	ft_putstr_fd("pb\n", 1);
}

