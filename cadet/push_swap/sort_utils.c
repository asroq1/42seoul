/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:59:26 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/11 18:08:55 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_top(t_stack_data *stack)
{
	return (stack->arr[stack->length - 1]);
}

int	get_mid_result(t_stack_data *stack)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < stack->length)
	{
		j = 0;
		k = 0;
		while (j < stack->length)
		{
			if (stack->arr[j] - stack->arr[i] > 0)
			{
				k++;
			}
			j++;
		}
		if (k == 2)
		{
			return (stack->arr[i]);
		}
		i++;
	}
	return (1);
}

int	get_bot(t_stack_data *stack)
{
	return (stack->arr[0]);
}

void	sort_two_three(t_stack_data *stack)
{
	if (check_input(stack))
		return ;
	if (stack->length == 2)
		sa(stack);
	else if (stack->arr[0] > stack->arr[2] && stack->arr[1] > stack->arr[0])
	{
		sa(stack);
		ra(stack);
	}
	else if (stack->arr[2] > stack->arr[1] && stack->arr[0] > stack->arr[2])
		sa(stack);
	else if (stack->arr[2] > stack->arr[0] && stack->arr[1] > stack->arr[2])
		rra(stack);
	else if (stack->arr[0] > stack->arr[1] && stack->arr[2] > stack->arr[0])
		ra(stack);
	else
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_b(t_stack_data *b, int length)
{
	int	i;

	i = 0;
	while (i < b->length && b->arr[i] != length)
	{
		printf("i ==> %d\n", i);
		i++;
	}
	while (i < b->length / 2 && i >= 0)
	{
		printf("rrb i ==> %d\n", i);
		rrb(b);
		i--;
	}
	while (i >= b->length / 2 && i < b->length - 1)
	{
		printf("rb i ==> %d\n", i);
		rb(b);
		i++;
	}
}
