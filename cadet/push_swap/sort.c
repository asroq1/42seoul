/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:43:17 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/01 11:26:43 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (get_top(a) <= i)
		{
			pb(a, b);
			i++;
		}
		else if (get_top(a) > i && get_top(a) <= i + chunk)
		{
			pb(a, b);
			rb(b);
			i++;
		}
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

void	large_command(t_stack_data *a, t_stack_data *b)
{
	int				i;
	int				x;
	int				chunk;

	i = 0;
	x = a->length;
	chunk = 0.000000053 * (x * x) + 0.03 * x + 14.5;
	a_to_b(a, b, chunk, i);
	b_to_a(a, b);
}

void	b_to_a(t_stack_data *a, t_stack_data *b)
{
	int	length;

	length = b->length - 1;
	while (b->length != 0)
	{
		sort_b(b, length);
		pa(a, b);
		length--;
	}
}

void	sort_stack(t_stack_data *a, t_stack_data *b)
{
	if (a->length <= 5)
	{
		small_command(a, b);
	}
	else
	{
		large_command(a, b);
	}
}
