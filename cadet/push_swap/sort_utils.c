/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:13:07 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/22 17:22:12 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	use_pivot(t_stack_data *a, int p1, int p2)
{
	if (a->a_top->content < p1)
	{
		pb(a);
		rb(a);
	}
	else if (a->a_top->content < p2)
	{
		pb(a);
	}
	else
	{
		ra(a);
	}
}

void	get_pivot_info(t_stack_data *a)
{
	int	i;
	int	p1;
	int	p2;

	i = a->size_a / 3;
	p1 = a->arr[i];
	i = a->size_a * 2 / 3;
	p2 = a->arr[i];
	i = a->size_a;
	while (i != 0)
	{
		use_pivot(a, p1, p2);
		i--;
	}	
}

int	set_a_location(int n, t_stack_data *stack)
{
	int	ret;

	if (n < get_stack_min(stack->a_top))
	{
		ret = set_a_location_mid(n, stack);
	}
	return (ret);
}

int	set_a_location_mid(int n, t_stack_data *stack)
{
	int		ret;
	t_node	*a;

	a = stack->a_top;
	ret = 1;
	while (a->next != NULL)
	{
		if (n > a->content && n < a->next->content)
		{
			break ;
		}
		ret++;
		a = a->next;
	}
	if (ret >= (stack->size_b + 1) / 2)
	{
		ret = (stack->size_b - ret) * -1;
	}
	return (ret);
}
