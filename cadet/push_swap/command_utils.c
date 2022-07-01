/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:26:56 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/01 10:57:33 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack_data *from)
{
	int	temp;

	temp = get_top(from);
	from->arr[from->length - 1] = from->arr[from->length - 2];
	from->arr[from->length - 2] = temp;
	return (0);
}

int	push(t_stack_data *from, t_stack_data *to)
{
	int	temp;

	temp = get_top(from);
	if (from->length != 0)
	{
		from->length--;
		to->arr[to->length] = temp;
		to->length++;
	}
	return (0);
}

int	rotate(t_stack_data *from)
{
	int	temp;
	int	i;

	i = from->length - 1;
	temp = get_top(from);
	while (i > 0)
	{
		from->arr[i] = from->arr[i - 1];
		i--;
	}
	from->arr[0] = temp;
	return (0);
}

int	reverse_rotate(t_stack_data *from)
{
	int	temp;
	int	i;

	i = 0;
	temp = get_bot(from);
	while (i < from->length - 1)
	{
		from->arr[i] = from->arr[i + 1];
		i++;
	}
	from->arr[from->length - 1] = temp;
	return (0);
}