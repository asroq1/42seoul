/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:16:18 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/01 11:27:37 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack_data *a)
{
	if (rotate(a) == 0)
	{
		ft_putstr_fd("ra\n", 1);
		return (0);
	}
	return (1);
}

int	rb(t_stack_data *b)
{
	if (rotate(b) == 0)
	{
		ft_putstr_fd("rb\n", 1);
		return (0);
	}
	return (1);
}

int	rr(t_stack_data *a, t_stack_data *b)
{
	if (rotate(a) == 0 || rotate(b) == 0)
	{
		ft_putstr_fd("rr\n", 1);
		return (0);
	}
	return (1);
}
