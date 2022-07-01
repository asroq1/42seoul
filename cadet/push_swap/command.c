/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:32:11 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/01 10:56:48 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack_data *a)
{
	if (swap(a) == 0)
	{
		ft_putstr_fd("sa\n", 1);
		return (0);
	}
	return (1);
}

int	sb(t_stack_data *b)
{
	if (swap(b) == 0)
	{
		ft_putstr_fd("sb\n", 1);
		return (0);
	}
	return (1);
}

int	ss(t_stack_data *a, t_stack_data *b)
{
	if (swap(a) == 0 || swap(b) == 0)
	{
		ft_putstr_fd("ss\n", 1);
		return (0);
	}
	return (1);
}

int	pa(t_stack_data *a, t_stack_data *b)
{
	if (push(b, a) == 0)
	{
		ft_putstr_fd("pa\n", 1);
		return (0);
	}
	return (1);
}

int	pb(t_stack_data *a, t_stack_data *b)
{
	if (push(a, b) == 0)
	{
		ft_putstr_fd("pb\n", 1);
		return (0);
	}
	return (1);
}
