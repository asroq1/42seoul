/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rerot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:06:59 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/30 10:59:06 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rerotate(t_stack_data *stack)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = get_bot(stack);
	while (i < stack->length - 1)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[stack->length - 1] = tmp;
	return (0);
}

int	rra(t_stack_data *stack)
{
	if (rerotate(stack) == 0)
	{
		ft_putstr_fd("rra\n", 1);
		return (0);
	}
	return (1);
}

int	rrb(t_stack_data *stack)
{
	if (rerotate(stack) == 0)
	{
		ft_putstr_fd("rrb \n", 1);
		return (0);
	}
	return (1);
}

int	rrr(t_stack_data *a, t_stack_data *b)
{
	if (rerotate(a) == 0 || rerotate(b) == 0)
	{
		ft_putstr_fd("rrr\n", 1);
		return (0);
	}
	return (1);
}
