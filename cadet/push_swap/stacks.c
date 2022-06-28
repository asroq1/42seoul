/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:08:32 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/28 18:50:33 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_stack(t_stack_data *a)
{
	int	n;

	n = 500;
	a->arr = malloc(sizeof(int) * n);
	if (a->arr == NULL)
	{
		occur_error(1);
	}
	a->size = 0;
	a->total = n;
}

void	get_a(t_stack_data *a, int n)
{
	int	*temp;
	int	i;

	i = a->size;
	if (a->size >= a->total)
	{
		temp = malloc(sizeof(int) * (a->total * 2));
		if (temp == 0)
			occur_error(1);
		ft_memcpy(temp, a->arr, (a->size * sizeof(int)));
		free(a->arr);
		a->arr = temp;
		a->total *= 2;
	}
	while (i > 0)
	{
		a->arr[i] = a->arr[i - 1];
		i--;
	}
	a->arr[0] = n;
	a->size++;
}
