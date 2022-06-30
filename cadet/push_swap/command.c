/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:32:11 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/30 20:24:21 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	push(t_stack_data *from, t_stack_data *dest)
// {
// 	int	tmp;

// 	tmp = get_top(from);
// 	if (from->length != 0)
// 	{
// 		from->length--;
// 		dest->arr[dest->length] = tmp;
// 		dest->length++;
// 	}
// 	return (0);
// }

// int	swap(t_stack_data *stack)
// {
// 	int	tmp;
// 	int	length;

// 	length = stack->length - 1;
// 	tmp = get_top(stack);
// 	stack->arr[length] = stack->arr[length - 1];
// 	stack->arr[length - 1] = tmp;
// 	return (0);
// }

// int	pa(t_stack_data *a, t_stack_data *b)
// {
// 	if (push(b, a) == 0)
// 	{
// 		ft_putstr_fd("pa\n", 1);
// 		return (0);
// 	}
// 	return (1);
// }

// int	pb(t_stack_data *a, t_stack_data *b)
// {
// 	if (push(a, b) == 0)
// 	{
// 		ft_putstr_fd("pb\n", 1);
// 		return (0);
// 	}
// 	return (1);
// }

// int	sa(t_stack_data *stack)
// {
// 	if (swap(stack) == 0)
// 	{
// 		ft_putstr_fd("sa\n", 1);
// 		return (0);
// 	}
// 	return (1);
// }

// int	sb(t_stack_data *stack)
// {
// 	if (swap(stack) == 0)
// 	{
// 		ft_putstr_fd("sb\n", 1);
// 		return (0);
// 	}
// 	return (1);
// }

// int	ss(t_stack_data *a, t_stack_data *b)
// {
// 	if (swap(a) == 0 || swap(b) == 0)
// 	{
// 		ft_putstr_fd("ss\n", 1);
// 		return (0);
// 	}
// 	return (1);
// }

int	ra(t_stack_data *a)
{
	if (rotate(a) == 0)
	{
		ft_putstr_fd("ra\n", 1);
		return (0);
	}
	return (1);
}
int	rb(t_stack_data *b)
{
	if (rotate(b) == 0)
	{
		ft_putstr_fd("rb\n", 1);
		return (0);
	}
	return (1);
}
int	rr(t_stack_data *a, t_stack_data *b)
{
	if (rotate(a) == 0 || rotate(b) == 0)
	{
		ft_putstr_fd("rr\n", 1);
		return (0);
	}
	return (1);
}
int	rra(t_stack_data *a)
{
	if (reverse_rotate(a) == 0)
	{
		ft_putstr_fd("rra\n", 1);
		return (0);
	}
	return (1);
}
int	rrb(t_stack_data *b)
{
	if (reverse_rotate(b) == 0)
	{
		ft_putstr_fd("rrb\n", 1);
		return (0);
	}
	return (1);
}
