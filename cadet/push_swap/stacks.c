/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:08:32 by hyunjung          #+#    #+#             */
/*   Updated: 2022/06/21 15:41:11 by hyunjung         ###   ########.fr       */
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
	t_stack_data	*new_node;
	t_node			*stack_a;

	new_node = NULL;
	new_node = malloc(sizeof(t_stack_data));
	stack_a = make_new_stack();
	new_node->arr = NULL;
	new_node->size_a = 0;
	new_node->a_top = stack_a;
	new_node->a_bottom = stack_a;
	new_node->size_b = 0;
	return (new_node);
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
		printf("arr[i] is ===> %d\n", (int)arr[i]);
		stack_data->a_bottom->next = new;
		stack_data->a_bottom = new;
		i++;
	}
	free(new);
}
