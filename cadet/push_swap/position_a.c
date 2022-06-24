/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:44:25 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/24 15:10:40 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// a스택에서 제일 작은 수를 찾기 위한 재귀함수
int	get_stack_min(t_node *a)
{
	int	result;

	result = a->content;
	while (a != 0)
	{
		if (result > a->content)
		{
			result = a->content;
		}
		a = a->next;
	}
	return (result);
}

// a스택에서 제일 큰 수를 찾기 위한 재귀함수
int	get_stack_max(t_node *a)
{
	int	result;

	result = a->content;
	while (a != 0)
	{
		if (result < a->content)
		{
			result = a->content;
		}
		a = a->next;
	}
	return (result);
}

int	set_a_position_min(t_stack_data *stack)
{
	int		i;
	int		result;
	int		tmp;
	t_node	*a;

	result = 0;
	tmp = 0;
	a = stack->a_top;
	i = get_stack_min(a);
	while (a != 0)
	{
		tmp = a->content;
		if (tmp == i)
		{
			break ;
		}
		result++;
		a = a->next;
	}
	if (result >= (stack->a_top + 1) / 2)
	{
		result = (stack->size_a - result) * -1;
	}
	return (result);
}

int	set_a_position_mid(t_stack_data *stack)
{

}

int	set_a_position_max(t_stack_data *stack)
{
	
}
