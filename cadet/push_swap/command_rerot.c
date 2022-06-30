/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rerot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:06:59 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/30 20:19:33 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	rerotate(t_stack_data *stack)
// {
// 	int	i;
// 	int	tmp;

// 	i = 0;
// 	tmp = get_bot(stack);
// 	while (i < stack->length - 1)
// 	{
// 		stack->arr[i] = stack->arr[i + 1];
// 		i++;
// 	}
// 	stack->arr[stack->length - 1] = tmp;
// 	return (0);
// }

// int	rra(t_stack_data *stack)
// {
// 	if (rerotate(stack) == 0)
// 	{
// 		ft_putstr_fd("rra\n", 1);
// 		return (0);
// 	}
// 	return (1);
// }

// int	rrb(t_stack_data *stack)
// {
// 	if (rerotate(stack) == 0)
// 	{
// 		ft_putstr_fd("rrb \n", 1);
// 		return (0);
// 	}
// 	return (1);
// }

// int	rrr(t_stack_data *a, t_stack_data *b)
// {
// 	rerotate(a);
// 	rerotate(b);
// 	ft_putstr_fd("rrr \n", 1);
// 	return (0);
// }
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

int	rrr(t_stack_data *a, t_stack_data *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
	return (0);
}
