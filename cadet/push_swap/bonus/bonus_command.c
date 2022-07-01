/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:28:33 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/01 17:37:24 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bonus_sa(t_stack_data *a)
{
	if (swap(a) == 0)
	{
		return (0);
	}
	return (1);
}

int	bonus_sb(t_stack_data *b)
{
	if (swap(b) == 0)
	{
		return (0);
	}
	return (1);
}

int	bonus_ss(t_stack_data *a, t_stack_data *b)
{
	if (swap(a) == 0 || swap(b) == 0)
	{
		return (0);
	}
	return (1);
}

int	bonus_pa(t_stack_data *a, t_stack_data *b)
{
	if (push(b, a) == 0)
	{
		return (0);
	}
	return (1);
}

int	bonus_pb(t_stack_data *a, t_stack_data *b)
{
	if (push(a, b) == 0)
	{
		return (0);
	}
	return (1);
}
