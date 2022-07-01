/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rerot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:06:59 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/01 11:24:21 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack_data *a)
{
	if (reverse_rotate(a) == 0)
	{
		ft_putstr_fd("rra\n", 1);
		return (0);
	}
	return (1);
}

int	rrb(t_stack_data *b)
{
	if (reverse_rotate(b) == 0)
	{
		ft_putstr_fd("rrb\n", 1);
		return (0);
	}
	return (1);
}

int	rrr(t_stack_data *a, t_stack_data *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
	return (0);
}
