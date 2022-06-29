/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:16:18 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/29 17:14:41 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ra(t_stack_data *a)
// {
// 	t_node	*tmp;

// 	if (a->size_a < 2)
// 		occur_error(2);
// 	tmp = a->a_top;
// 	a->a_top = a->a_top->next;
// 	a->a_bottom->next = tmp;
// 	a->a_bottom = tmp;
// 	a->a_bottom->next = NULL;
// 	ft_putstr_fd("ra\n", 1);
// }

// void	rb(t_stack_data *b)
// {
// 	t_node	*tmp;

// 	if (b->size_b < 2)
// 		occur_error(2);
// 	tmp = b->b_top;
// 	b->b_top = b->b_top->next;
// 	b->b_bottom->next = tmp;
// 	b->b_bottom = tmp;
// 	b->b_bottom->next = NULL;
// 	ft_putstr_fd("rb\n", 1);
// }

// void	rr(t_stack_data *stacks)
// {
// 	t_node	*tmp;

// 	if (stacks->size_a < 2 || stacks->size_b < 2)
// 		occur_error(2);
// 	tmp = stacks->a_top;
// 	stacks->a_top = stacks->a_top->next;
// 	stacks->a_bottom->next = tmp;
// 	stacks->a_bottom = tmp;
// 	stacks->a_bottom->next = NULL;
// 	tmp = stacks->b_top;
// 	stacks->b_top = stacks->b_top->next;
// 	stacks->b_bottom->next = tmp;
// 	stacks->b_bottom = tmp;
// 	stacks->b_bottom->next = NULL;
// 	ft_putstr_fd("rr\n", 1);
// }

// int	ra(t_stack_data *a)
// {
// 	if (rotate(a) == 0)
// 	{
// 		ft_putstr_fd("ra\n", 1);
// 		return (0);
// 	}
// 	return (1);
// }

// int	rb(t_stack_data *b)
// {
// 	if (rotate(b) == 0)
// 	{
// 		ft_putstr_fd("rb\n", 1);
// 		return (0);
// 	}
// 	return (1);
// }

// int	rra(t_stack_data *a)
// {
// 	if (rroate(a) == 0)
// 	{
// 		ft_putstr_fd("rra\n", 1);
// 		return (0);
// 	}
// 	return (1);
// }

// int	rrb(t_stack_data *b)
// {
// 	if (rroate(b) == 0)
// 	{
// 		ft_putstr_fd("rrb \n", 1);
// 		return (0);
// 	}
// 	return (1);
// }

// int	rr(t_stack_data *a, t_stack_data *b)
// {
// 	if (rotate(a) == 0 || rotate(b) == 0)
// 	{
// 		ft_putstr_fd("rr\n", 1);
// 		return (0);
// 	}
// 	return (1);
// }
