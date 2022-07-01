/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_command_rerot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:32:02 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/01 17:36:19 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bonus_rra(t_stack_data *a)
{
	if (reverse_rotate(a) == 0)
	{
		ft_putstr_fd("rra\n", 1);
		return (0);
	}
	return (1);
}

int	bonus_rrb(t_stack_data *b)
{
	if (reverse_rotate(b) == 0)
	{
		ft_putstr_fd("rrb\n", 1);
		return (0);
	}
	return (1);
}

int	bonus_rrr(t_stack_data *a, t_stack_data *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
	return (0);
}
