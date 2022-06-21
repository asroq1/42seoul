/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:08:32 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/21 12:05:55 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*make_new_stack(void)
{
	t_node	*new_mem;

	new_mem = NULL;
	new_mem = (t_node *)malloc(sizeof(t_node));
	new_mem->content = 0;
	new_mem->next = NULL;
	return (new_mem);
}

t_stack_data	*get_new_stacks(void)
{
	t_stack_data	*new_mem;
	t_node			*stack_a;

	new_mem = NULL;
	new_mem = malloc(sizeof(t_stack_data));
	stack_a = make_new_stack();
	new_mem->arr = NULL;
	new_mem->size_a = 0;
	new_mem->a_top = stack_a;
	new_mem->a_bottom = stack_a;
	new_mem->size_b = 0;
	return (new_mem);
}

void	change_to_stack(t_stack_data *stack_data, int *arr, int size)
{
	int		i;
	t_node	*new;

	i = 0;
	while (i < size)
	{
		new = make_new_stack();
		stack_data->size_a += 1;
		stack_data->a_bottom->content = (int)arr[i];
		stack_data->a_bottom->next = new;
		stack_data->a_bottom = new;
		i++;
	}
	free(new);
}

void	validate_arr(int *arr, int i, int size)
{
	int	j;
	int	tmp;
	int	bomb;

	bomb = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				bomb++;
			}
		j++;
		}
		if (arr[i] == arr[i + 1])
			occur_error(1);
		i++;
	}
	if (bomb == 0)
		occur_error(1);
}
