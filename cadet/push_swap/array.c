/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:19:14 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/30 18:54:21 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing_arr(t_stack_data *a)
{
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	tmp = (int *)malloc(sizeof(int) * a->length);
	if (tmp == NULL)
		occur_error(1);
	while (i < a->length)
	{
		j = 0;
		tmp[i] = 0;
		while (j < a->length)
		{
			if (a->arr[i] > a->arr[j])
			{
				tmp[i]++;
			}
			j++;
		}
		i++;
	}
	free(a->arr);
	a->arr = NULL;
	a->arr = tmp;
}
