/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:13:07 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/24 15:13:29 by hyunjung         ###   ########.fr       */
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

// b스택의 탑의 값을 가져와 최적의 값을 구하기 위한 함수이다. 
int	set_a_position(int n, t_stack_data *stack)
{
	int	result;

	if (n < get_stack_min(stack->a_top))
	{
		result = set_a_position_min(stack);
	}
	else if (n > get_stack_max(stack->a_top))
	{
		result = set_a_position_max(stack);
	}
	else
	{
		result = set_a_position_mid(stack);
	}
	return (result);
}
