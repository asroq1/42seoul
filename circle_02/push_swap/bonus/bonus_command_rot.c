/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_command_rot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:31:59 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/01 17:36:38 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bonus_ra(t_stack_data *a)
{
	if (rotate(a) == 0)
	{
		ft_putstr_fd("ra\n", 1);
		return (0);
	}
	return (1);
}

int	bonus_rb(t_stack_data *b)
{
	if (rotate(b) == 0)
	{
		ft_putstr_fd("rb\n", 1);
		return (0);
	}
	return (1);
}

int	bonus_rr(t_stack_data *a, t_stack_data *b)
{
	if (rotate(a) == 0 && rotate(b) == 0)
	{
		ft_putstr_fd("rr\n", 1);
		return (0);
	}
	return (1);
}
