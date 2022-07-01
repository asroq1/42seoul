/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:08:32 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/01 11:26:24 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_stack(t_stack_data *stack)
{
	int	n;

	n = 500;
	stack->arr = malloc(sizeof(int) * n);
	if (stack->arr == 0)
	{
		occur_error(1);
	}
	stack->length = 0;
	stack->total = n;
}

void	get_a(t_stack_data *stack, int n)
{
	int	*temp;
	int	i;

	i = stack->length;
	if (stack->length >= stack->total)
	{
		temp = malloc(sizeof(int) * (stack->total * 2));
		if (temp == 0)
			occur_error(1);
		ft_memcpy(temp, stack->arr, (stack->length * sizeof(int)));
		free(stack->arr);
		stack->arr = temp;
		stack->total *= 2;
	}
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = n;
	stack->length++;
}

void	get_b(t_stack_data *stack, int length)
{
	stack->arr = malloc(sizeof(int) * length);
	if (stack->arr == 0)
	{
		occur_error(1);
	}
	stack->length = 0;
	stack->total = length;
}
