/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:43:17 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/30 13:44:36 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_top(t_stack_data *stack)
{
	return (stack->arr[stack->length - 1]);
}

int	get_mid(t_stack_data *stack)
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

void	small_command(t_stack_data *a, t_stack_data *b)
{
	while (a->length > 3)
	{
		while (get_top(a) >= get_mid(a))
		{
			ra(a);
		}
		pb(a, b);
	}
	if (a->length == 2 || a->length == 3)
	{
		sort_two_three(a);
	}
	while (b->length > 0)
	{
		pa(a, b);
	}
	if (get_top(a) > a->arr[a->length - 2])
	{
		sa(a);
	}
}

void	a_to_b(t_stack_data *a, t_stack_data *b, int chunk, int i)
{
	int	length;

	length = a->length - 1;
	while (a->length != 0)
	{
		/* 1. a의 top이 i보다 작다면 b스택으로 넘긴다. */
		if (get_top(a) <= i)
		{
			pb(a, b);
			i++;
		}
		/* 2. a의 top이 i보다 크지만 i + chunk보다 작다면 b의 스택으로 옮기고, rb로 인덱스를 ++한다.*/
		else if (get_top(a) > i && get_top(a) <= i + chunk)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		/* 3. a의 top이 i + chunk보다 크다면 a의 스택에 유지한다. */
		else if (get_top(a) > (i + chunk))
		{
			if (i < a->length / 2 && i >= 0)
				rra(a);
			else
				ra(a);
		}
		length--;
	}
}

void	sort_b(t_stack_data *b, int length)
{
	int	i;

	i = 0;
	/* 1. i가 length보다 작고, arr의 값이 length가 아닐 때는 i++ */
	while (i < b->length && b->arr[i] != length)
	{
		i++;
	}
	/* 2. length을 반으로 자르고, i가 반으로 잘린 것보다 작고, i가 0이거나 0보다 클때  */
	while (i < b->length / 2 && i >= 0)
	{
		rrb(b);
		i--;
	}
	/* 3. length를 반 자르고, i가 그거보다 크거나 같지만 i가 len - 1보단 작을때 rb*/
	while (i >= b->length / 2 && i < b->length - 1)
	{
		rb(b);
		i++;
	}
}

void	b_to_a(t_stack_data *b, t_stack_data *a)
{
	int	length;

	length = b-> length - 1;
	while (b->length != 0)
	{
		sort_b(b, length);
		pa(a, b);
		length--;
	}
}

void	large_command(t_stack_data *a, t_stack_data *b)
{
	int				i;
	int				x;
	int				chunk;

	i = 0;
	x = a->length;
	chunk = 0.000000053 * (x * x) + 0.03 * x + 14.5;
	a_to_b(a, b, chunk, i);
	b_to_a(b, a);
}

void	sort_stack(t_stack_data *a, t_stack_data *b)
{
	// int i = 0;
	// while (a->arr[i] != 0)
	// {
	// 	printf("a->arr[%d] === %d\n", i, a->arr[i]);
	// 	i++;
	// }
	// 	printf("a->arr[5] === %d\n",a->arr[5]);
	// 	printf("top stack is ==> %d\n", get_top(a));
	if (a->length <= 5)
	{
		small_command(a, b);
	}
	else
	{
		large_command(a, b);
	}
}
