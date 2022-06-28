/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:26:56 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/28 18:40:03 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	push(t_stack_data *from, t_stack_data *to)
// {
// 	int	tmp;

// 	tmp = top_stack(from);
// 	if (from != 0)
// 	{
// 		from->size_a--;
// 		to->arr[to->size_a] = tmp;
// 		to->size_b++;
// 	}
// 	return (0);
// }

// int	swap(t_stack_data *from)
// {
// 	int	tmp;

// 	tmp = top_stack(from);
// 	from->arr[from->size_a - 1] = from->arr[from->size_a - 2];
// 	from->arr[from->size_a - 2] = tmp;
// 	return (0);
// }

// int	rotate(t_stack_data *from)
// {
// 	int	i;
// 	int	tmp;

// 	i = from->size_a - 1;
// 	tmp = top_stack(from);
// 	while (i > 0)
// 	{
// 		from->arr[i] = from->arr[i - 1];
// 		i--;
// 	}
// 	from->arr[0] = tmp;
// 	return (0);
// }

// int	rroate(t_stack_data *from)
// {
// 	int	i;
// 	int	tmp;

// 	i = 0;
// 	tmp = bot_stack(from);
// 	while (i < from->size_a - 1)
// 	{
// 		from->arr[i] = from ->arr[i + 1];
// 		i++;
// 	}
// 	from->arr[from->size_a - 1] = tmp;
// 	return (0);
// }
