/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:16:18 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/30 11:07:17 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack_data *stack)
{
	int	i;
	int	tmp;

	i = stack->length - 1;
	tmp = get_top(stack);
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = tmp;
	return (0);
}

int	ra(t_stack_data *stack)
{
	if (rotate(stack) == 0)
	{
		ft_putstr_fd("ra\n", 1);
		return (0);
	}
	return (1);
}

int	rb(t_stack_data *stack)
{
	if (rotate(stack) == 0)
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
